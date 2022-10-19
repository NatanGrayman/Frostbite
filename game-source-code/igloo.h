#ifndef IGLOO_H
#define IGLOO_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include <vector>

class Igloo
{
    public:
    /** @brief The igloo object works by generating all the rectangles that compose the igloo, the rectangles are then displayed as required.
    *This implementation may be less memory efficient but it is more time efficient than recreating the rectangles each frame.
    *The pieces are stored in a vector of rectangles.
    *@param secondaryIgloo a boolean argument to denote if this is the second players igloo.
    */
        Igloo(bool secondaryIgloo=false);
        virtual ~Igloo();
        void drawIgloo(sf::RenderWindow& window, int stage);
    protected:

    private:
        vector<sf::RectangleShape> iglooPieces;
        void createBottomLayers(bool secondaryIgloo);
        void createRoofLayers(bool secondaryIgloo);
        void createDoor(bool secondaryIgloo);
};

#endif // IGLOO_H
