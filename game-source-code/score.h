#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "temperature.h"

class Score
{
    public:
        Score();
        virtual ~Score();
        void drawScore(sf::RenderWindow& window);
        void loadFont(bool secondaryScore=false);
        void changeScore(int difference){scoreCount+=difference;};
        void resetScore(){scoreCount=0;};
        int getScore(){return scoreCount;};
    protected:

    private:
        int scoreCount=0;
        sf::Font scoreFont;
        sf::Text scoreText;

};

#endif // SCORE_H
