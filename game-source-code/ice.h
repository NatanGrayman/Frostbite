#ifndef ICE_H
#define ICE_H

#include "Entity.h"


class Ice : public Entity
{
    public:
        Ice(float velocity); //constructor that sets an initial velocity of the ice.
        virtual ~Ice(); //destructor
        void changePosition(float x, float y); // set a co-ordinate position of the Ice.
        void movePosition(); //move the Ice block.

    protected:

    private:
};

#endif // ICE_H
