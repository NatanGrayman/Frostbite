#include "secondPlayer.h"

SecondPlayer::SecondPlayer()
{
    //ctor
}

SecondPlayer::~SecondPlayer()
{
    //dtor
}

void SecondPlayer::processEvents(sf::Keyboard::Key key, bool checkPressed, bool gameFinished)
{
    if(checkPressed==true)
    {
        if(key==sf::Keyboard::S && grounded)             //If down key was pressed and the player is grounded,  set movement of player downwards (jump).
        {
            yMomentum=5;
            grounded=false;
            jumpSound.play();
        }
        if(key==sf::Keyboard::W && grounded)               //If up key was pressed and the player is grounded, set movement of player upwards(jump).
        {
            if(gameFinished && (xPosition+36)>550 && xPosition<650 && yPosition==160){finishGame();};
            yMomentum=-5;
            grounded=false;
            jumpSound.play();
        }
        if(key==sf::Keyboard::A)                         //If left key was pressed, set movement of player left.
        {
            xMomentum=-5;
            sprite.setScale(-1,1);                         //Flip Bailey , to face right, when click left.
            xPosition+=(rightFacing*32);                   //If rightfacing (1 or 0) then add width bailey, to adjust for mirroring
            rightFacing=false;

        }
        if(key==sf::Keyboard::D)                       //If right key was pressed, set movement of player right.
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
