#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"

class Enemy
{
    public:
        Enemy(float level, int iVelocity);
        virtual ~Enemy();
        void drawInWindow(sf::RenderWindow &window, int frames); // function to render each enemy in the row to the window.
        void loadTexture(string name); //load the enemy image to each enemy block in the row.
        bool findCollision( Entity entity);
        int getMomentum(){return momentum;};
        bool movePosition();
    protected:

    private:
        vector<Entity> enemyRow; //create a vector of enemy objects to form the enemyRow.
        int num=3;          //number of enemy blocks in a row.
        sf::Texture texture;
        int momentum;
        sf::Texture enemyTexture;//
        vector<string> crabs{"Crab_1.png","Crab_2.png","Crab_3.png","Crab_4.png","Crab_5.png","Crab_6.png" };
        //vector<string> crabs{"Clam_1.png","Clam_2.png","Clam_3.png","Clam_4.png","Clam_5.png","Clam_6.png", "Clam_7", "Clam_8","Clam_9"};
};

#endif // ENEMY_H
