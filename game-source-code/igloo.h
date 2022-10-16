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
        Igloo();
        virtual ~Igloo();
        void drawIgloo(sf::RenderWindow& window, int stage);
    protected:

    private:
        vector<sf::RectangleShape> iglooPieces;
        void createBottomLayers();
        void createRoofLayers();
        void createDoor();
};

#endif // IGLOO_H
