#include "igloo.h"

Igloo::Igloo(bool secondaryIgloo)
{
    // The igloo object works by generating all the rectangles that compose the igloo, the rectangles are then displayed as required.
    //This implementation may be less memory efficient but it is more time efficient than recreating the rectangles each frame.
    //The pieces are stored in a vector of rectangles.
    createBottomLayers(secondaryIgloo);
    createRoofLayers(secondaryIgloo);
    createDoor(secondaryIgloo);
}

void Igloo::createBottomLayers(bool secondaryIgloo)
{
    for(int i=0; i<12; i++) //create the first 3 layers of iceblocks in rows of 4.
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(500+((i%4)*50)-(250*secondaryIgloo),120-(int(i/4))*20));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
}
void Igloo::createRoofLayers(bool secondaryIgloo)
{
    for(int j=0; j<2; j++) //create the final layer of two iceBlocks.
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(550+(50*j)-(250*secondaryIgloo),60));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
    //create the final igloo piece
    sf::RectangleShape iglooPart(sf::Vector2f(50,20));
    iglooPart.setPosition(sf::Vector2f(575-(250*secondaryIgloo),40));
    iglooPart.setFillColor(sf::Color(125,125,125));
    iglooPieces.push_back(iglooPart);
}
void Igloo::createDoor(bool secondaryIgloo)
{
    //create the door to the igloo.
    sf::RectangleShape iglooDoor(sf::Vector2f(50,40));
    iglooDoor.setPosition(sf::Vector2f(575-(250*secondaryIgloo),100));
    iglooDoor.setFillColor(sf::Color(0,0,0));
    iglooPieces.push_back(iglooDoor);
}

void Igloo::drawIgloo(sf::RenderWindow& window, int stage)
{
    // according to the current stage of the game, IE: how many iceblocks have been landed on, loop through the stage and display the igloo pieces.
    for(int i=0; i<stage; i++)
    {
        sf::RectangleShape piece = iglooPieces[i];
        window.draw(piece);
    }
}

Igloo::~Igloo()
{
    //dtor
}
