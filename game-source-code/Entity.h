#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include <string>

using namespace std;

/**@brief Entity Class
*creates a base object that can be moved, displayed, and collide with another Entity object.
*/
class Entity                                                    //Entity is parent class for all 'live' objects that are used.
{
public:
    /**
    *@brief Default Entity constructor initializes the Entity at the origin with no motion.
    */
    Entity();                                                   //Constructor
    /**
    *@brief The overloaded constructor allows for the creation of an Entity at any position with an initial velocity.
    *@param float xInitial refers to the initial x position of the object.
    *@param float yInitial refers to the initial y position of the object.
    *@param float xVelocity refers to the initial x velocity of the object.
    */
    Entity(float xInitial, float yInitial, float xVelocity){xPosition=xInitial;yPosition=yInitial; xMomentum=xVelocity;};
    /**
    *@brief Function to draw the Entity in the game window
    *@param window indicates the game window where the object must be displayed.
    */
    void drawInWindow(sf::RenderWindow &window);
    /**
    *@brief Function to update the objects sprite to the current position of the Entity.
    *@param window indicates the game window where the object must be displayed.
    */
    void positionUpdate();
    /**
    *@brief Function to load an image to the Entity.
    *@param texture is the texture that holds the objects Image.
    *@param name is the relative path of the image that is loaded.
    */
    void loadTexture(sf::Texture &texture, string name);
    /**
    *@brief Function to check whether the object has collided with another object.
    *@param entity refers to another Entity that's position is being compared against.
    *@return boolean variable on whether a collision was detected or not.
    */
    bool findCollision(Entity entity);
    /**
    *@brief Function to simulate the movement of the Entity.
    */
    void movePosition();
    /**
    *@brief Function mirror the image over the x axis when the player changes walking direction.
    */
    void flipSprite(){sprite.scale(-1,1);};
    /**
    *@brief Function to get the current x position of the Entity.
    *@return the x position is returned.
    */
    float getXPosition(){return xPosition;};
    /**
    *@brief Function to get the current y position of the Entity.
    *@return the y position is returned.
    */
    float getYPosition(){return yPosition;};
    /**
    *@brief Function to get the bounds of the object's sprite.
    *@return Returns the bounding rectangle of the sprite.
    */
    sf::FloatRect getBounds(){return sprite.getGlobalBounds();};
protected:
    sf::Sprite sprite;   //sprite initialized.
    float xPosition;    //Store xPosition
    float yPosition;   //Store yPosition of entities
    float xMomentum;   //Store the x direction momentum of entity
    float yMomentum;   //Store the y direction momentum of entity
private:

};

#endif // ENTITY_H_INCLUDED
