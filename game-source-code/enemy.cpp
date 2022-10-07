#include "enemy.h"

Enemy::Enemy(float level, int iVelocity)  //constuctor
{
    for(int i=0;i<num; i++)
    {
        momentum = iVelocity;
        Entity entity(-(95+64)*i, 215, iVelocity);
        enemyRow.push_back(entity);
    }
}
Enemy::~Enemy()
{

}
void Enemy::drawInWindow(sf::RenderWindow &window, int frames)
{
    loadTexture(crabs[int(frames/20)%6]);//
    for(int i=0;i<num; i++) //loop through each ice block in the vector,
    {
        enemyRow[i].drawInWindow(window); // draw the current ice block.
    }
}

void Enemy::movePosition() //update the iceRows position/s.
{
    for(int i=0;i<num; i++) //loop through each ice block in the vector,
    {
        enemyRow[i].movePosition(); //move the individual Ice object.
    }
}

void Enemy::loadTexture(string name)
{
    for(int i=0;i<num; i++)
    {
        enemyRow[i].loadTexture(texture, name);
    }
}

bool Enemy::findCollision(Entity entity) //search for a collision of each Ice block with inputted co-ordinates.
{
    for(int i=0;i<num; i++) //loop through each IceRow in iceLevels,
    {
        if(enemyRow[i].findCollision(entity)) //search for a collision for the current IceRow.
        {
            return true;                    //If a collision is found, return true.
        }
    }
    return false;                           //Otherwise return false.
}

