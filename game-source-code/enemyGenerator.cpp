#include "enemyGenerator.h"

EnemyGenerator::EnemyGenerator()
{
    enemyImages.push_back(crabs);
    enemyImages.push_back(clams);
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
    bool direction = rand()%2;
    bool pickEnemy = rand()%2;
    Enemy newEnemy(215+(70*rowNum), 2-(4*direction), enemyImages[pickEnemy]);
    enemyList.push_back(newEnemy);
}
void EnemyGenerator::resetEnemies()
{
    if(enemyList.size()==0){return;};
    for(int enemy=0;enemy<=enemyList.size();enemy++)
    {
        enemyList.erase(enemyList.begin()+enemy);
    }
}
void EnemyGenerator::movePosition()
{
    cout<<enemyList.size()<<endl;
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
int EnemyGenerator::findCollision(Entity entity)
{
    for(int k=0;k<enemyList.size(); k++)
    {
        if(enemyList[k].findCollision(entity))
        {
            return enemyList[k].getMomentum();
        }
    }
    return 0;
}
