#include "enemyGenerator.h"

EnemyGenerator::EnemyGenerator()
{
    //ctor
}

EnemyGenerator::~EnemyGenerator()
{
    //dtor
}

void EnemyGenerator::generateEnemy()
{
    int rowNum = rand()%4;
    if(rowIsOccupied[rowNum]){return;};
    rowIsOccupied[rowNum] = true;
    Enemy newEnemy(215+(70*rowNum), 2);
    enemyList.push_back(newEnemy);
}
void EnemyGenerator::movePosition()
{
    for(int k=0;k<enemyList.size(); k++)
    {
        if(enemyList[k].movePosition())
        {
            enemyList.erase(enemyList.begin() + k);
            rowIsOccupied[k] = false;
        }
    }
}
void EnemyGenerator::drawInWindow(sf::RenderWindow &window, int frame)
{
    for(int k=0;k<enemyList.size(); k++)
    {
        enemyList[k].drawInWindow(window, frame);
    }
}
bool EnemyGenerator::findCollision(Entity entity)
{
    for(int k=0;k<enemyList.size(); k++)
    {
        if(enemyList[k].findCollision(entity))
        {
            return true;
        }
    }
    return false;
}
