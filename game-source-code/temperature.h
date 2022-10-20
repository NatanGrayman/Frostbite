#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;
/**
*@brief  Temperature Class
*that manages the Game clock, displays the time remaining, adjusts member variables as needed.
*@authors Gilad Kangisser (2367017)
*@authors Natan Grayman (2344104)
*/
class Temperature
{
    public:
        Temperature();
        virtual ~Temperature();
        /**
        *@brief  Function that returns the amount of time remaining before the player will freeze
        *@return The ime remaining before the player will freeze.
        */
        int getTimeRemaining(){return int(initialTemperature-int(clock.getElapsedTime().asSeconds()));};
        /**
        *@brief  Function that draws the temperature for each frame
        *@param window is the Game window that the temperature must be drawn onto.
        *@param alive boolean that indicates whether the timer needs to be reset - whenever the player dies
        */
        void drawTemperature(sf::RenderWindow& window, bool alive);
        /**
        *@brief  Function that loads the font and text states.
        */
        void loadFont();
        /**
        *@brief  Function that resets the current timer of the clock, either when the player dies or finishes a level.
        */
        void resetTemperature();
        /**
        *@brief  Function that runs out the clock at an increased rate as part of the animation of the igloo being built.
        */
        void enterIgloo(sf::RenderWindow& window, int second);
    protected:

    private:
        sf::Clock clock;
        int initialTemperature = 45;
        sf::Font temperatureFont;
        sf::Text temperatureText;
};

#endif // TEMPERATURE_H
