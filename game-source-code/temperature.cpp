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
    temperatureText.setCharacterSize(20);
    temperatureText.setPosition(sf::Vector2f(50,40));
    temperatureText.setFillColor(sf::Color(132,148,255));
}

void Temperature::drawTemperature(sf::RenderWindow& window)
{
        temperatureText.setString(to_string(getTimeRemaining()));
        window.draw(temperatureText);
}
