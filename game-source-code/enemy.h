#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"

class Enemy
{
    public:
        Enemy(float level, int iVelocity, vector<string> images);
        virtual ~Enemy();
        void drawInWindow(sf::RenderWindow &window, int frames); // function to render each enemy in the row to the window.
        void loadTexture(string name); //load the enemy image to each enemy block in the row.
        int findCollision( Entity entity);
        int getMomentum(){return momentum;};
        bool movePosition();
    protected:

    private:
        int num=3;          //number of enemy blocks in a row.
        vector<Entity> enemyRow; //create a vector of enemy objects to form the enemyRow.
        int momentum;
        sf::Texture texture;
        vector<string> imgNames;
};

#endif // ENEMY_H
