#include "score.h"
#include <iostream>
using namespace std;
Score::Score()
{
    //ctor
}

Score::~Score()
{
    //dtor
}


void Score::loadFont(bool secondaryScore)
{
    if(!scoreFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;};  //Loading the font for score
    scoreText.setFont(scoreFont);
    scoreText.setCharacterSize(22);
    scoreText.setPosition(sf::Vector2f(150+(150*secondaryScore),20));
    scoreText.setFillColor(sf::Color(132,148,255));
}

void Score::drawScore(sf::RenderWindow& window)   //method to draw the score
{
        scoreText.setString(to_string(scoreCount));
        window.draw(scoreText);
}
