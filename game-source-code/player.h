#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

class Player : public Entity
{
    public:
        Player();   //Constructor
        virtual ~Player();  //Destructor
        void processEvents(sf::Keyboard::Key key, bool checkPressed);  //Member function to act on user input
        void movePlayer();    //Member function to move the position of the player.
    protected:

    private:
        void checkXBoundary();    //Function to check not out of bounds in horizontal direction
        void checkYBoundary();    //Function to check not out of bounds in vertical direction
};

#endif // PLAYER_H
