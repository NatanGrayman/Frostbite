#include "iceLevels.h"
#include "iceRow.h"
#include <vector>

IceLevels::IceLevels()
{
     int iVelocity=1;   //variable to store the velocity that the Ice will move at.
     for(int j=0;j<4; j++) //populate the iceLevels vector with (4) individual IceRows.
    {
        IceRow iceRow = IceRow(255+(j*70), iVelocity); //create an icerow with the initial velocity and a height - that is shifted down each iteration to create the different levels.
        iceLevels.push_back(iceRow); //add the iceRow to the vector.
        iVelocity*=-1; // reverse the velocity for the next row, in order for the rows to be moving in opposite directions.
    }
    buffer.loadFromFile("resources/iceBreakSound.wav");
    iceBreak.setBuffer(buffer);
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
void IceLevels::processSprite(int j)
{
    for(j=0;j<4;j++)
    {
        if(activated[j]&&activated2[j]){loadOneRowTexture("resources/landOnIceBlock.png", j);}
        else if(activated[j]){loadOneRowTexture("resources/player1LandedBlock.png",j);}
        else if(activated2[j]&&!activated[j]){loadOneRowTexture("resources/player2LandedBlock.png", j);}
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

int IceLevels::findCollision(float x, float y, Entity entity, bool secondP) //search for a collision of each Ice block with inputted co-ordinates.
{
    for(int j=0;j<4; j++) //loop through each IceRow in iceLevels,
    {
        if(iceLevels[j].findCollision(x, y, entity)) //search for a collision for the current IceRow.
        {
            if(!secondP){loadOneRowTexture("resources/landOnIceBlock.png", j);};
            if(!secondP && activated[j]!=1){iceBreak.play();};
            if(secondP &&activated2[j]!=1){iceBreak.play();};
            if(count(activated.begin(), activated.end(), 1) == 4){loadTexture("resources/iceBlock.png");};
            return j;                    //If a collision is found, return true.
        }
    }
    iceBreak.stop();
    return -1;                           //Otherwise return false.
}

void IceLevels::resetActive(bool initial, bool secondary) // reset the state of each row of iceBlocks.
{
    if(!secondary && (count(activated.begin(), activated.end(), 1) == 4 ||initial))
    {
        loadTexture("resources/iceBlock.png");
        for(int j=0;j<4;j++)
        {
            activated[j] = 0;
        }
    }
    if(secondary && (count(activated2.begin(), activated2.end(), 1) == 4 ||initial))
    {
        loadTexture("resources/iceBlock.png");
        for(int j=0;j<4;j++)
        {
            activated2[j] = 0;
        }
    }
}

void IceLevels::changeDirection(bool resetRows, float yPos)
{
    if(!resetRows){iceLevels[(yPos-215)/70].changeDirection(); return;};
    for(int j=0;j<4;j++)
    {
        if((j%2==0)&&iceLevels[j].getMomentum()<0){iceLevels[j].changeDirection();};
        if((j%2==1)&&iceLevels[j].getMomentum()>0){iceLevels[j].changeDirection();};
    }

}
