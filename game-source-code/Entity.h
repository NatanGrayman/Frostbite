#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include <string>

using namespace std;

class Entity                                                    //Entity is parent class for all 'live' objects that are used.
{
public:
    Entity();                                                   //Constructor
    Entity(float xInitial, float yInitial, float xVelocity){xPosition=xInitial;yPosition=yInitial; xMomentum=xVelocity;};
    void drawInWindow(sf::RenderWindow &window);
    void positionUpdate();
    void loadTexture(sf::Texture &texture, string name);
    float getXPosition(){return xPosition;};                   //Getter for testing purposes.
    float getYPosition(){return yPosition;};                   //Getter for testing purposes.
    sf::FloatRect getBounds(){return sprite.getGlobalBounds();};
    bool findCollision(Entity entity);
    void movePosition();
    void flipSprite(){sprite.scale(-1,1);};
protected:
    sf::Sprite sprite;   //sprite initialized.
    float xPosition;    //Store xPosition
    float yPosition;   //Store yPosition of entities
    float xMomentum;   //Store the x direction momentum of entity
    float yMomentum;   //Store the y direction momentum of entity
private:

};

#endif // ENTITY_H_INCLUDED
