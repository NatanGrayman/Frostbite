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
        void resetEnemies();
    protected:

    private:
        vector<Enemy> enemyList;
        vector<vector<string>> enemyImages;
        vector<string> crabs{"Crab_1.png","Crab_2.png","Crab_3.png","Crab_4.png","Crab_5.png","Crab_6.png","Crab_6.png", "Crab_5.png","Crab_4.png","Crab_3.png","Crab_2.png","Crab_1.png"};
        vector<string> clams{"Clam_1.png","Clam_2.png","Clam_3.png","Clam_4.png","Clam_5.png","Clam_6.png", "Clam_7.png", "Clam_8.png","Clam_9.png", "Clam_9.png", "Clam_8.png","Clam_7.png","Clam_6.png","Clam_5.png","Clam_4.png","Clam_3.png", "Clam_2.png", "Clam_1.png"};
        vector<bool> rowIsOccupied{0,0,0,0};
};

#endif // ENEMYGENERATOR_H
