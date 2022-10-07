#include "igloo.h"

Igloo::Igloo()
{
    // The igloo object works by generating all the rectangles that compose the igloo, the rectangles are then displayed as required.
    //This implementation may be less memory efficient but it is more time efficient than recreating the rectangles each frame.
    //The pieces are stored in a vector of rectangles.
    for(int i=0; i<12; i++) //create the first 3 layers of iceblocks in rows of 4.
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(500+((i%4)*50),120-(int(i/4))*20));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
    for(int j=0; j<2; j++) //create the final layer of two iceBlocks.
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(550+(50*j),60));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
    //create the final igloo piece
    sf::RectangleShape iglooPart(sf::Vector2f(50,20));
    iglooPart.setPosition(sf::Vector2f(575,40));
    iglooPart.setFillColor(sf::Color(125,125,125));
    iglooPieces.push_back(iglooPart);

    //create the door to the igloo.
    sf::RectangleShape iglooDoor(sf::Vector2f(50,40));
    iglooDoor.setPosition(sf::Vector2f(575,100));
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
