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
        void drawInWindow(sf::RenderWindow &window); // function to render each ice block in the row to the window.
        void loadTexture(string name); //load the ice block image to each ice block in the row.
        bool findCollision( Entity entity);
        int getMomentum(){return momentum;};
        void movePosition();
    protected:

    private:
        vector<Entity> enemyRow; //create a vector of Ice objects to form the IceRow.
        int num=3;          //number of ice blocks in a row.
        sf::Texture texture;
        int momentum;
};

#endif // ENEMY_H
