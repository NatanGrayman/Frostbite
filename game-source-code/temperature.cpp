#include "temperature.h"

Temperature::Temperature()
{
    //ctor
}

Temperature::~Temperature()
{
    //dtor
}

void Temperature::loadFont()
{
    if(!temperatureFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;};
    temperatureText.setFont(temperatureFont);
    temperatureText.setCharacterSize(22);
    temperatureText.setPosition(sf::Vector2f(50,50));
    temperatureText.setFillColor(sf::Color(132,148,255));
}

void Temperature::drawTemperature(sf::RenderWindow& window, bool alive)
{
    if(!alive){clock.restart();};
    temperatureText.setString(to_string(getTimeRemaining()));
    window.draw(temperatureText);
}

void Temperature::resetTemperature()
{
  clock.restart();
}

void Temperature::enterIgloo(sf::RenderWindow& window, int seconds)
{
    temperatureText.setString(to_string(seconds));
    window.draw(temperatureText);
}
