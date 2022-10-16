#include "player.h"
#include "Entity.h"

Player::Player()
{
    xPosition = 300;   //Setting the initial Position;
    yPosition = 160;   //Setting the initial Position
    grounded=true;     //Bailey starts off grounded
    ticks=0;           //Bailey has not been in the air
    lives=3;           //Bailey starts with 3 lives
    buffer.loadFromFile("resources/playerJumpSound.wav");
    jumpSound.setBuffer(buffer);
}

Player::Player(float xInitial, float yInitial)  //Created for testing purposes
{
    xPosition = xInitial;
    yPosition = yInitial;
    grounded=true;
    ticks=0;
    lives=3;
}

void Player::resetPlayer(bool life)
{
    //Restart the initial game settings.
    xPosition = 300;
    yPosition = 160;
    grounded=true;
    gameWon=false;
    ticks=0;
    if(life){lives=3;};
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
            jumpSound.play();
        }
        if(key==sf::Keyboard::Up && grounded)               //If up key was pressed and the player is grounded, set movement of player upwards(jump).
        {
            if(gameFinished && (xPosition+36)>550 && xPosition<650 && yPosition==160){finishGame();};
            yMomentum=-5;
            grounded=false;
            jumpSound.play();
        }
        if(key==sf::Keyboard::Left)                         //If left key was pressed, set movement of player left.
        {
            xMomentum=-5;
            sprite.setScale(-1,1);                         //Flip Bailey , to face right, when click left.
            xPosition+=(rightFacing*32);                   //If rightfacing (1 or 0) then add width bailey, to adjust for mirroring
            rightFacing=false;

        }
        if(key==sf::Keyboard::Right)                       //If right key was pressed, set movement of player right.
        {
            xMomentum=5;
            sprite.setScale(1,1);                          //Scale Bailey.
            xPosition-=(!rightFacing*32);                  //If rightfacing (1 or 0) then add width bailey, to adjust for mirroring
            rightFacing=true;
        }
    }
    else
    {
        xMomentum=0;                                 //If the key has been released by user then stop horizontal movement.
    }
}

bool Player::checkDeath() //Method to check if player dies, ie hits the 'water'.
{
       //if you grounded, IE: not in the air, and you are not either landed on an iceBlock or in the safe zone (y=160) then the player is in the water and dies.
        if(grounded && !(landed || yPosition==160)){lives--;xPosition=300;yPosition=160; return false;};
        return true;
}

void Player::freezeDeath()  //Method to check if temperature runs out.
{
    lives--;
    xPosition=300;
    yPosition=160;
}

void Player::movePlayer(int enemyVelocity)                   //function to move player.
{
    if(!grounded)               //Check not grounded to set time in 'air'
    {
        ticks++;               //increase time in 'air'
    }
    if(ticks>=15)              //If he has been in the 'air' for fifteen frames
    {
        jumpSound.stop();
        grounded=true;         //set as grounded
        yMomentum=0;           //Stop vertical movement
        ticks=0;               //Reset airtime count
    }
    //if the player has collided with an enemy, movement is disabled. Unless mid-jump in which case the jump is completed.
    if(enemyVelocity!=0){xMomentum=0; floorMomentum=enemyVelocity; if(landed){yMomentum=0;}};
    xPosition+=xMomentum;     //Change the horizontal position of the player
    xPosition+=floorMomentum; //add the momentum of the floor to the players position
    checkXBoundary();         //check the screen boundaries
    yPosition+=yMomentum;     //Change the vertical position of the player
    checkYBoundary();         //check the screen boundaries
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

void Player::finishGame() // function when player wins the game/level.
{
    gameWon = true;
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

void Player::drawLives(sf::RenderWindow& window) // draw the remaining lives of the player.
{
    playerText.setString(to_string(lives));
    window.draw(playerText);
}

void Player::loadTexture(string name)   //Member function to load any texture, passing in its name.
{
    if (!texture.loadFromFile(name))  //load from file specific texture.
    {
        cout<<"Error in loading texture";          //Error message if does not load
    }
    sprite.setTexture(texture);                       //Set the texture of the sprite.
}
