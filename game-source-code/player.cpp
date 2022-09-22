#include "Player.h"
#include "entity.h"

Player::Player()
{
    yPosition = 160;   //Setting the initial Position
}

Player::~Player()
{
    //dtor
}

void Player::processEvents(sf::Keyboard::Key key, bool checkPressed)   //Act on user input
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
            yMomentum=-5;
            grounded=false;
        }
        if(key==sf::Keyboard::Left)                         //If left key was pressed, set movement of player left.
        {
            xMomentum=-5;
        }
        if(key==sf::Keyboard::Right)                       //If right key was pressed, set movement of player right.
        {
            xMomentum=5;
        }
    }
    else
    {
            xMomentum=0;                                 //If the key has been released by user then stop horizontal movement.
    }
}

void Player::movePlayer()                   //function to move player.
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
    xPosition+=xMomentum;     //Change the horizontal position of the player
    yPosition+=yMomentum;     //Change the vertical position of the player
    positionUpdate();         //Now update the position of sprite.
}
