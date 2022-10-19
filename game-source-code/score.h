#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "temperature.h"
/**
*@brief  Score Class
that manages the player's score and increases and decreases accordingly
*/
class Score
{
    public:
        Score();
        virtual ~Score();
        /**
        *@brief  Function
        */
        void drawScore(sf::RenderWindow& window);
        /**
        *@brief  Function to set initial states of variables and objects, according to the game design.
        */
        void loadFont(bool secondaryScore=false);
        /**
        *@brief  Function to set initial states of variables and objects, according to the game design.
        */
        void changeScore(int difference){scoreCount+=difference;};
        /**
        *@brief  Function to set initial states of variables and objects, according to the game design.
        */
        void resetScore(){scoreCount=0;};
        /**
        *@brief  Function to set initial states of variables and objects, according to the game design.
        */
        int getScore(){return scoreCount;};
    protected:

    private:
        int scoreCount=0;
        sf::Font scoreFont;
        sf::Text scoreText;

};

#endif // SCORE_H
