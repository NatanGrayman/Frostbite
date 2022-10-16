#include "enemy.h"

Enemy::Enemy(float level, int iVelocity, vector<string> images)  //constuctor
{
    for(int i=0;i<num; i++)   //Loop for each enemy in row
    {
        momentum = iVelocity;
        Entity entity(-(momentum/2)*(95+64)*i+(800*(momentum-1)/-3), level, iVelocity);   //Create entitiy with an intitial velocity
        if(iVelocity<0){entity.flipSprite();};
        enemyRow.push_back(entity);
    }
    imgNames=images;
}
Enemy::~Enemy()
{

}
void Enemy::drawInWindow(sf::RenderWindow &window, int frames)
{
    loadTexture("resources/" +imgNames[int(frames/20)%imgNames.size()]);//load a new image for the crab every 20 frames, this creates the animation.
    for(int i=0;i<num; i++) //loop through each enemy block in the vector,
    {
        enemyRow[i].drawInWindow(window); // draw the current enemy block.
    }
}

bool Enemy::movePosition() //update the enemy position/s.
{
    if(momentum>0 && enemyRow[num-1].getXPosition()>800){return true;};
    if(momentum<0 && enemyRow[num-1].getXPosition()<0){return true;};
    for(int i=0;i<num; i++) //loop through each enemy block in the vector,
    {
        enemyRow[i].movePosition(); //move the individual enemy object.
    }
    return false;
}

void Enemy::loadTexture(string name)
{
    for(int i=0;i<num; i++)
    {
        enemyRow[i].loadTexture(texture, name);
    }
}

int Enemy::findCollision(Entity entity) //search for a collision of each enemy block with inputted co-ordinates.
{
    for(int i=0;i<num; i++) //loop through each enemy in enemy row,
    {
        if(enemyRow[i].findCollision(entity)) //search for a collision for the current enemy.
        {
            return momentum;                    //If a collision is found, return true.
        }
    }
    return false;                           //Otherwise return false.
}

