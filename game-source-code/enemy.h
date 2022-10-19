#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
/**
*@brief Enemy Class
* that uses composition to control the logic of each row of enemies within the four levels present.
*/
class Enemy
{
    public:
        /**
        *@brief Default Constructor that populates the individual enemy objects into each row.
        *@param float level which indicates the the specific row, numbering from top to bottom.
        *@param int iVelocity which inputs the enemy object's initial velocity.
        *@param vector<string> images refers to the vector of each enemy sprite which is set to crab as default.
        */
        Enemy(float level, int iVelocity, vector<string> images = {"Crab_1.png"});
         /**
        *@brief Default Destructor
        */
        virtual ~Enemy();
        /**
        *@brief Function to render each enemy in the row to the window.
        *@param window indicates the game window where the object must be displayed.
        */
        void drawInWindow(sf::RenderWindow &window, int frames); // function to render each enemy in the row to the window.
        /**
        *@brief Function to load the enemy image to each enemy block in the row.
        *@param string name specifies the image for each enemy object, which creates animation.
        */
        void loadTexture(string name); //load the enemy image to each enemy block in the row.
        /**@brief Function to search for a collision for enemies with particular entity.
        * @param Entity entity used to find the collision between the bounding box of respective entity.
        * @return Returns true if a collision is found, otherwise false.
        */
        int findCollision(Entity entity);
        /**@brief Getter Function to get the momentum of each enemy row.
        * @return Returns the momentum of each enemy row.
        */
        int getMomentum(){return momentum;};
        /**
        *@brief Function to update the enemy position/s.
        *@return true if out of bounds, thereby deleting enemies out of bounds/inactive.
        */
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
