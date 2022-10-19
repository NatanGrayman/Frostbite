#include "temperature.h"

Temperature::Temperature()  //Temperature constructor.
{
    //ctor
}

Temperature::~Temperature()
{
    //dtor
}

void Temperature::loadFont()   //Load temperature font
{
    if(!temperatureFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;}; //Loading font
    temperatureText.setFont(temperatureFont);
    temperatureText.setCharacterSize(22);
    temperatureText.setPosition(sf::Vector2f(50,50));
    temperatureText.setFillColor(sf::Color(132,148,255));
}

void Temperature::drawTemperature(sf::RenderWindow& window, bool alive)
{
    if(!alive){clock.restart();};   //If Bailey is not alive, restart the time.
    temperatureText.setString(to_string(getTimeRemaining())+"°");  //get the amount of time remaining
    window.draw(temperatureText);
}

void Temperature::resetTemperature()
{
  clock.restart();    //restart the clock
}

void Temperature::enterIgloo(sf::RenderWindow& window, int seconds)  //When enter igloo, printing new time.
{
    temperatureText.setString(to_string(seconds)+"°");
    window.draw(temperatureText);
}
