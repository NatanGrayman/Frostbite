#include "player.h"
#include "Entity.h"

Player::Player()
{
    xPosition = 300;
    yPosition = 160;   //Setting the initial Position
    grounded=true;
    ticks=0;
    lives=3;
}

Player::Player(float xInitial, float yInitial)
{
    xPosition = xInitial;
    yPosition = yInitial;
    grounded=true;
    ticks=0;
    lives=3;
}

void Player::resetPlayer()
{
    xPosition = 300;
    yPosition = 160;   //Setting the initial Position
    grounded=true;
    ticks=0;
    lives=3;
}

Player::~Player()
{
    //dtor
}

void Player::processEvents(sf::Keyboard::Key key, bool checkPressed, bool gameFinished=false)   //Act on user input
{
    if(checkPressed==true)
    {
        if(key==sf::Keyboard::Down && grounded)             //If down key was pressed and the player is grounded,  set movement of player downwards (jump).
        {
            yMomentum=5;
            grounded=false;
        }
        if(key==sf::Keyboard::Up && grounded)               //If up key was pressed and the player is grounded, set movement of player upwards(jump).
        {
            if(gameFinished && (xPosition+36)>550 && xPosition<650){finishGame();};
            yMomentum=-5;
            grounded=false;
        }
        if(key==sf::Keyboard::Left)                         //If left key was pressed, set movement of player left.
        {
            xMomentum=-5;
            sprite.setScale(-1,1);
            xPosition+=(rightFacing*32);
            rightFacing=false;

        }
        if(key==sf::Keyboard::Right)                       //If right key was pressed, set movement of player right.
        {
            xMomentum=5;
            sprite.setScale(1,1);
            xPosition-=(!rightFacing*32);
            rightFacing=true;
        }
    }
    else
    {
        xMomentum=0;                                 //If the key has been released by user then stop horizontal movement.
    }
}

bool Player::checkDeath()
{
        if(grounded && !(landed || yPosition==160)){lives--;xPosition=300;yPosition=160; return false;};
        return true;
}

void Player::die()
{
    lives--;
    xPosition=300;
    yPosition=160;
}

void Player::movePlayer(bool enemyCollision)                   //function to move player.
{
    if(!grounded)               //Check not grounded to set time in 'air'
    {
        ticks++;               //increase time in 'air'
    }
    if(ticks>=15)              //If he has been in the 'air' for fifteen frames
    {
        grounded=true;         //set as grounded
        yMomentum=0;           //Stop vertical movement
        ticks=0;               //Reset airtime count
    }
    if(enemyCollision){xMomentum=0; floorMomentum=2; if(landed){yMomentum=0;}};
    xPosition+=xMomentum;     //Change the horizontal position of the player
    xPosition+=floorMomentum; //add the momentum of the floor to the players position
    checkXBoundary();
    yPosition+=yMomentum;     //Change the vertical position of the player
    checkYBoundary();
    positionUpdate();         //Now update the position of sprite.
}

void Player::checkXBoundary()
{
    if(xPosition>800-(rightFacing*32))   //Check the horizontal boundary with the total width minus Bailey's width.
    {
        xPosition=800-(rightFacing*32);  //Ensure stays at boundary position.
    }
    else if(xPosition-(!rightFacing*32)<=0)  //Check the leftmost horizontal boundary
    {
        xPosition=0+(32*!rightFacing);      //Set as 0 to ensure does not go out of bounds.
    }
}
void Player::checkYBoundary()
{

    if(yPosition>440)    //Check the vertical  bottom boundary and ensure can not 'jump' down on lowest ice-level.
    {
        yPosition=440;
    }
    else if(yPosition<160)  //Check the vertical upward boundary and ensure can not 'jump' up on highest level (iceland).
    {
        yPosition=160;
    }
}

void Player::finishGame()
{
    cout<<"Player has won the game"<<endl;
}

void Player::loadFont()
{
    if(!playerFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;};
    playerText.setFont(playerFont);
    playerText.setCharacterSize(22);
    playerText.setPosition(sf::Vector2f(150,50));
    playerText.setFillColor(sf::Color(132,148,255));
}

void Player::drawLives(sf::RenderWindow& window)
{
    playerText.setString(to_string(lives));
    window.draw(playerText);
}
