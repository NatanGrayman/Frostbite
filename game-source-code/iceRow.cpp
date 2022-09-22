#include "IceRow.h"

IceRow::IceRow(float level, int iVelocity)
{
    for(int i=0;i<num; i++)
    {
        Ice ice(iVelocity);
        ice.changePosition(-96*i, level);
        iceRow.push_back(ice);
    }
}

IceRow::~IceRow()
{
    //dtor
}

void IceRow::drawEachInWindow(sf::RenderWindow &window)
{
    for(int i=0;i<num; i++)
    {
        iceRow[i].drawInWindow(window);
    }
}

void IceRow::movePosition()
{
    for(int i=0;i<num; i++)
    {
        iceRow[i].movePosition();
    }
}

void IceRow::loadEachTexture(sf::Texture& texture, string name)
{
    for(int i=0;i<num; i++)
    {
        iceRow[i].loadTexture(texture, name);
    }
}
