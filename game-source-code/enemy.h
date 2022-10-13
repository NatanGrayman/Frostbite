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
        vector<string> crabs{"crab_1.png","crab_2.png","crab_3.png","crab_4.png","crab_5.png","crab_6.png" };
};

#endif // ENEMY_H
