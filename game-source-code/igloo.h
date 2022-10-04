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
        void drawIgloo(sf::RenderWindow& window);
        void incrementStage(){iglooStage++;};
        int getStage(){return iglooStage;};
    protected:

    private:

        int iglooStage=0;
        vector<sf::RectangleShape> iglooPieces;
};

#endif // IGLOO_H
