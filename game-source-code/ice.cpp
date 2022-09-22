#include "Ice.h"

Ice::Ice(float velocity)    //Constructor to set the speed of the iceBlock
{
    xMomentum=velocity;
}

Ice::~Ice()                //Destructor
{
    //dtor
}

void Ice::movePosition()   //Member function to move the iceBlock
{
    xPosition+=xMomentum;  //Increase horizonal position as horizontal speed increases
    if(xMomentum>0)        //If the iceBlock is moving:
    {
        int n = int(xPosition/800);          //xPosition/game window-width-size gives a fraction either 0 or 1 as an integer
        xPosition=float(int(xPosition)%800); //Modulas of game-window-width-size shows how much further the ice block has moved passed boundary
        xPosition=xPosition-(n*95);          //If the Ice is passed the width of the object, subtract its width - enables wrapping.
    }
    else if(xPosition<-95)                   //if the ice moves to the left of the screen.
    {
            xPosition+=895;                 // push it to the far rigtht to wrap it around the screen.
    }

    positionUpdate();                       //update the position of the Ice.
}

void Ice::changePosition(float x, float y)  //function to set the position of the Ice.
{
    xPosition=x;                            //set xPosition to x input.
    yPosition=y;                            //set yPosition to y input.
    sprite.setPosition(sf::Vector2f(x,y));  //move the sprite to the new position.
}
