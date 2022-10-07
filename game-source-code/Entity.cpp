#include "Entity.h"

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

void Entity::movePosition()   //Member function to move the iceBlock
{
    xPosition+=xMomentum;  //Increase horizonal position as horizontal speed increases
    positionUpdate();                       //update the position of the Ice.
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

bool Entity::findCollision(Entity entity) //find whether the Ice block is colliding with the given co-ordinates.
{
    //If the given co-ordinates are contained within the bounded rectangle of the Ice Block, then return true, else false.
    sf::FloatRect boundingBox1 = sprite.getGlobalBounds();
    sf::FloatRect boundingBox2 = entity.getBounds();
    if(boundingBox1.intersects(boundingBox2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
