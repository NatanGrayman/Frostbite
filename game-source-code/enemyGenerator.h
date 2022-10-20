#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H
#include "enemy.h"
/**
*@brief EnemyGenerator Class
* that uses composition and random processes to generate and control varyig rows of Enemy objects.
*@authors Gilad Kangisser (2367017)
*@authors Natan Grayman (2344104)
*/
class EnemyGenerator
{
    public:
    /**
    *@brief
    * function that initializes the generators members.
    */
        EnemyGenerator();
        virtual ~EnemyGenerator();
        /**
        *@brief Function to render all enemies to the window.
        *@param window indicates the game window where the objects must be displayed.
        *@param frame integer is passed to allow for the enemies motion animation to occur.
        */
        void drawInWindow(sf::RenderWindow &window, int frame);
        /**
        *@brief Function to search for a collision between any Enemy and an alternate Entity.
        * @param Entity entity used to find the collision between the bounding box of respective Entities.
        * @return Returns true if a collision is found, otherwise false.
        */
        int findCollision(Entity entity);
        /**
        *@brief Function to randomly generate an enemy with random position, direction and type(crab or clam).
        * @param random int can be used to generate a deterministic Enemy.
        */
        void generateEnemy(int random=-1);
        /**
        *@brief Function to move all Enemy objects to their updated positions.
        */
        void movePosition();
        /**
        * @brief Function to reset the existing Enemies in order to clear the Game for a new round/life.
        */
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
