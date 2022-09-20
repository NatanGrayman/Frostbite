#include "entity.h"

Entity::Entity()        //Constuctor
{
    //Initialize all momentums and positions of the object.
     xMomentum=0;
     yMomentum=0;
     xPosition=0;
     yPosition=0;
}
void Entity::drawInWindow(sf::RenderWindow &window)   //Member Function to draw the object in the window.
{
    window.draw(sprite);                                 //Draw the sprite.
}

void Entity::positionUpdate()                         //Member function to update the position variables
{
    sprite.setPosition(sf::Vector2f(xPosition,yPosition));
}

void Entity::loadTexture(sf::Texture &texture, string name)   //Member function to load any texture, passing in its name.
{
    if (!texture.loadFromFile("resources/" +name))  //load from file specific texture.
    {
        cout<<"Error in loading texture";          //Error message if does not load
    }
    sprite.setTexture(texture);                       //Set the texture of the sprite.
    //sf::Vector2f scale=obj.getScale();
}
