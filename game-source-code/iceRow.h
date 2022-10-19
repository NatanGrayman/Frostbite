#ifndef ICEROW_H
#define ICEROW_H
#include "ice.h"
#include <vector>
/**
*@brief IceRow Class
* that uses composition to control the logic of each row of ice within the four levels present.
*/
class IceRow
{
    public:
        /**
        *@brief Default Constructor that populates the individual Ice objects into each row.
        *@param float level which indicates the the specific row, numbering from top to bottom.
        *@param int iVelocity which inputs the Ice object's initial velocity.
        */
        IceRow(float level, int iVelocity);
        /**
        *@brief Default Destructor
        */
        virtual ~IceRow();
        /**
        *@brief Function to render each ice block in the row to the window.
        *@param window indicates the game window where the object must be displayed.
        */
        void drawInWindow(sf::RenderWindow &window); // function to render each ice block in the row to the window.
        /**
        *@brief Function to move each ice block in the row.
        */
        void movePosition();                         // move each ice block in the row.
        /**
        *@brief Function to load the ice block image to each ice block in the row.
        *@param string name specifies the image for each Ice object.
        */
        void loadTexture(string name); //load the ice block image to each ice block in the row.
        /**@brief Function to search for a collision of each Ice block with inputted co-ordinates.
        * @param float x which is used to see if the co-ordinates are contained within the bounded rectangle of collison.
        * @param float y which is used to check if the co-ordinates are contained within the bounded rectangle of collison.
        * @param Entity entity used to find the collision between the bounding box of respective entity.
        * @return Returns true if a collision is found, otherwise false.
        */
        bool findCollision(float x, float y, Entity entity);
        /**@brief Getter Function to get the momentum of each icerow.
        * @return Returns the momentum of each icerow.
        */
        int getMomentum(){return momentum;};
        /**@brief Function to change the current direction of the icerow and loading the image for each Ice object.
        */
        void changeDirection();
    protected:

    private:
        vector<Ice> iceRow; //create a vector of Ice objects to form the IceRow.
        int num=3;          //number of ice blocks in a row.
        int momentum;
        sf::Texture texture;
};

#endif // ICEROW_H
