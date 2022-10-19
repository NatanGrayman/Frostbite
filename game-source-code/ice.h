#ifndef ICE_H
#define ICE_H

#include "Entity.h"
/**
*@brief Ice Class
*A type of Entity descendant that models the ice throughout the runtime of the game/s.
*/

class Ice : public Entity
{
    public:
        /**@brief Default Constuctor
        *@param float velocity refers to the velocity  which controls the speed of the iceBlock.
        */
        Ice(float velocity); //constructor that sets an initial velocity of the ice.
        /**@brief Default Destructor
        */
        virtual ~Ice(); //destructor
        /**@brief Function to set the position of the ice.
        * @param float x which sets the Xposition to that of x input
        * @param float y which sets the Yposition to that of y input
        */
        void changePosition(float x, float y); // set a co-ordinate position of the Ice.
        /**@brief Function to move the iceBlock
        */
        void movePosition(); //move the Ice block.
         /**@brief Function to find whether the Ice block is colliding with the given co-ordinates.
        * @param float x which is used to see if the co-ordinates are contained within the bounded rectangle of collison.
        * @param float y which is used to check if the co-ordinates are contained within the bounded rectangle of collison.
        * @param Entity entity used to find the collision between the bounding box of respective entity.
        */
        bool findCollision(float x, float y, Entity entity);
        /**@brief Function to change the momentum of iceBlock to the opposite direction.
        */
        void changeDirection(){xMomentum*=-1;};
    protected:

    private:
};

#endif // ICE_H
