#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H
#include "enemy.h"

class EnemyGenerator
{
    public:
        EnemyGenerator();
        virtual ~EnemyGenerator();
        void drawInWindow(sf::RenderWindow &window, int frame);
        int findCollision(Entity entity);
        void generateEnemy();
        void movePosition();
    protected:

    private:
        vector<Enemy> enemyList;
        vector<bool> rowIsOccupied{0,0,0,0};
};

#endif // ENEMYGENERATOR_H
