#include "iceRow.h"

IceRow::IceRow(float level, int iVelocity)  //constuctor
{
    for(int i=0;i<num; i++) //populate the vector with individual Ice objects
    {
        momentum = iVelocity;
        Ice ice(iVelocity); //create an Ice object with the inputted initial velocity.
        ice.changePosition(-(95+64)*i, level);  //set the initital position of the ice block, shift the ice blocks by their width and the gap between them.
        iceRow.push_back(ice); //add the Ice to the vector.
    }
}

IceRow::~IceRow()
{
    //dtor
}

void IceRow::drawInWindow(sf::RenderWindow &window)
{
    for(int i=0;i<num; i++) //loop through each ice block in the vector,
    {
        iceRow[i].drawInWindow(window); // draw the current ice block.
    }
}

void IceRow::movePosition() //update the iceRows position/s.
{
    for(int i=0;i<num; i++) //loop through each ice block in the vector,
    {
        iceRow[i].movePosition(); //move the individual Ice object.
    }
}

void IceRow::loadTexture(/*sf::Texture& texture,*/ string name)
{
    for(int i=0;i<num; i++) //loop through each ice block in the vector,
    {
        iceRow[i].loadTexture(texture, name); //load the image for each Ice object.
    }
}

bool IceRow::findCollision(float x, float y, Entity entity) //search for a collision of each Ice block with inputted co-ordinates.
{
    for(int i=0;i<num; i++) //loop through each IceRow in iceLevels,
    {
        if(iceRow[i].findCollision(x, y, entity)) //search for a collision for the current IceRow.
        {
            return true;                    //If a collision is found, return true.
        }
    }
    return false;                           //Otherwise return false.
}

void IceRow::changeDirection()
{
    momentum*=-1;
    for(int i=0;i<num; i++) //loop through each ice block in the vector,
    {
        iceRow[i].changeDirection(); //load the image for each Ice object.
    }
}
