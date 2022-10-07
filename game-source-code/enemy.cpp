#include "enemy.h"

Enemy::Enemy(float level, int iVelocity)  //constuctor
{
    for(int i=0;i<num; i++)   //Loop for each enemy in row
    {
        momentum = iVelocity;
        Entity entity(-(95+64)*i, 215, iVelocity);   //Create entitiy with an intitial velocity
        enemyRow.push_back(entity);
    }
}
Enemy::~Enemy()
{

}
void Enemy::drawInWindow(sf::RenderWindow &window, int frames)
{
    loadTexture(crabs[int(frames/20)%6]);//load a new image for the crab every 20 frames, this creates the animation.
    for(int i=0;i<num; i++) //loop through each enemy block in the vector,
    {
        enemyRow[i].drawInWindow(window); // draw the current enemy block.
    }
}

void Enemy::movePosition() //update the enemy position/s.
{
    for(int i=0;i<num; i++) //loop through each enemy block in the vector,
    {
        enemyRow[i].movePosition(); //move the individual enemy object.
    }
}

void Enemy::loadTexture(string name)
{
    for(int i=0;i<num; i++)
    {
        enemyRow[i].loadTexture(texture, name);
    }
}

bool Enemy::findCollision(Entity entity) //search for a collision of each enemy block with inputted co-ordinates.
{
    for(int i=0;i<num; i++) //loop through each enemy in enemy row,
    {
        if(enemyRow[i].findCollision(entity)) //search for a collision for the current enemy.
        {
            return true;                    //If a collision is found, return true.
        }
    }
    return false;                           //Otherwise return false.
}

