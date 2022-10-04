#include "igloo.h"

Igloo::Igloo()
{
    for(int i=0; i<12; i++)
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(500+((i%4)*50),120-(int(i/4))*20));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
    for(int j=0; j<2; j++)
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(550+(50*j),60));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
    sf::RectangleShape iglooPart(sf::Vector2f(50,20));
    iglooPart.setPosition(sf::Vector2f(575,40));
    iglooPart.setFillColor(sf::Color(125,125,125));
    iglooPieces.push_back(iglooPart);
    sf::RectangleShape iglooDoor(sf::Vector2f(50,40));
    iglooDoor.setPosition(sf::Vector2f(575,100));
    iglooDoor.setFillColor(sf::Color(0,0,0));
    iglooPieces.push_back(iglooDoor);
}

void Igloo::drawIgloo(sf::RenderWindow& window)
{
    for(int i=0; i<iglooStage; i++)
    {
        sf::RectangleShape piece = iglooPieces[i];
        window.draw(piece);
    }
}

Igloo::~Igloo()
{
    //dtor
}
