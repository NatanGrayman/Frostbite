#ifndef IGLOO_H
#define IGLOO_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include <vector>
/** @brief Igloo object works by generating all the rectangles that compose the igloo, the rectangles are then displayed as required.
*This implementation may be less memory efficient but it is more time efficient than recreating the rectangles each frame.
*The pieces are stored in a vector of rectangles.
*@param secondaryIgloo a boolean argument to denote if this is the second players igloo.
*/
class Igloo
{
    public:
        /** @brief Igloo constructor generates and stores the rectangle objects by calling private subfunctions.
        *@param secondaryIgloo a boolean argument to denote if this is the second players igloo, which will cause a positional shift.
        */
        Igloo(bool secondaryIgloo=false);
        virtual ~Igloo();
        /** @brief Function to draw the Igloo at the current frame.
        *@param window refers to the canvas object that the Igloo is displayed upon.
        *@param stage, an Integer that refers to the current stage of the igloo that has been built/must be displayed.
        */
        void drawIgloo(sf::RenderWindow& window, int stage);
    protected:

    private:
        vector<sf::RectangleShape> iglooPieces;
        void createBottomLayers(bool secondaryIgloo);
        void createRoofLayers(bool secondaryIgloo);
        void createDoor(bool secondaryIgloo);
};

#endif // IGLOO_H
