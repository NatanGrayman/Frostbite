#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;
class Temperature
{
    public:
        Temperature();
        virtual ~Temperature();
        int getTimeRemaining(){return int(initialTemperature-int(clock.getElapsedTime().asSeconds()));};
        void drawTemperature(sf::RenderWindow& window, bool alive);
        void loadFont();
        void resetTemperature();
        void enterIgloo(sf::RenderWindow& window, int second);
    protected:

    private:
        sf::Clock clock;
        int initialTemperature = 45;
        sf::Font temperatureFont;
        sf::Text temperatureText;
};

#endif // TEMPERATURE_H
