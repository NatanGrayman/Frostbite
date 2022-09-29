#include "iceLevels.h"
#include "iceRow.h"
#include <vector>

IceLevels::IceLevels()
{
     int iVelocity=2;   //variable to store the velocity that the Ice will move at.
     for(int j=0;j<4; j++) //populate the iceLevels vector with (4) individual IceRows.
    {
        IceRow iceRow = IceRow(255+(j*70), iVelocity); //create an icerow with the initial velocity and a height - that is shifted down each iteration to create the different levels.
        iceLevels.push_back(iceRow); //add the iceRow to the vector.
        iVelocity*=-1; // reverse the velocity for the next row, in order for the rows to be moving in opposite directions.
    }
}

IceLevels::~IceLevels()
{
    //dtor
}

void IceLevels::drawInWindow(sf::RenderWindow &window) //function to draw each IceRow in the IceLevels.
{
    for(int j=0;j<4; j++) //loop through each IceRow in iceLevels,
    {
        iceLevels[j].drawInWindow(window); //render each iceRow in the window.
    }
}

void IceLevels::movePosition()
{
    for(int j=0;j<4; j++) //loop through each IceRow in iceLevels,
    {
        iceLevels[j].movePosition(); //move the current IceRow to its new positions.

    }
}

void IceLevels::loadTexture(/*sf::Texture& texture,*/ string name)
{
    for(int j=0;j<4; j++) //loop through each IceRow in iceLevels,
    {
        iceLevels[j].loadTexture(/*texture,*/ name); //load the ice block texture for each row.
    }
}

void IceLevels::loadOneRowTexture(/*sf::Texture& texture,*/ string name, int rowNum)
{
    iceLevels[rowNum].loadTexture(/*texture,*/ name);
}

int IceLevels::findCollision(float x, float y) //search for a collision of each Ice block with inputted co-ordinates.
{
    for(int j=0;j<4; j++) //loop through each IceRow in iceLevels,
    {
        if(iceLevels[j].findCollision(x, y)) //search for a collision for the current IceRow.
        {
            loadOneRowTexture("landOnIceBlock.png", j);
            activated[j] = true;
            if(count(activated.begin(), activated.end(), 1) == 4){loadTexture("iceBlock.png");};
            return j;                    //If a collision is found, return true.
        }
    }
    return -1;                           //Otherwise return false.
}

void IceLevels::resetActive()
{
    if(count(activated.begin(), activated.end(), 1) == 4)
    {
        for(int j=0;j<4;j++)
        {
            activated[j] = 0;
        }
    }
}
