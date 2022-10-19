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
        *@brief  Function to draw the player's score
        *@param window refers to the game window where the score must be drawn into.
        */
        void drawScore(sf::RenderWindow& window);
        /**
        *@brief  Function to load the font of the text that displays the score.
        *@param secondaryScore denotes whether it is the score of the second player which will cause a positional shift.
        */
        void loadFont(bool secondaryScore=false);
        /**
        *@brief  Function to update the score.
        *@param difference indicates the points gained or lossed that must be added to the current value.
        */
        void changeScore(int difference){scoreCount+=difference;};
        /**
        *@brief  Function to reset or initialize the value of the player's score.
        */
        void resetScore(){scoreCount=0;};
        /**
        *@brief  Function to get the current value of the player's score.
        *@return scoreCount returns the Integer value of the players score.
        */
        int getScore(){return scoreCount;};
    protected:

    private:
        int scoreCount=0;
        sf::Font scoreFont;
        sf::Text scoreText;

};

#endif // SCORE_H
