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


void Score::loadFont()
{
    if(!scoreFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;};
    scoreText.setFont(scoreFont);
    scoreText.setCharacterSize(24);
    scoreText.setPosition(sf::Vector2f(50,20));
    scoreText.setFillColor(sf::Color::Red);
}

void Score::drawScore(sf::RenderWindow& window)
{
        scoreText.setString(to_string(scoreCount));
        window.draw(scoreText);
}
