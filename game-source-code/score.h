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
        void loadFont();
        void changeScore(int difference){scoreCount+=difference;};
        void resetScore(){scoreCount=0;};
        int getScore(){return scoreCount;};
    protected:

    private:
        int scoreCount=0;
        sf::Font scoreFont;
        sf::Text scoreText;
        sf::Sprite background; //Sprite initalised to hold the background.
        sf::RenderTexture backgroundTexture; //Create RenderTexture to store background
        void createBackground(); //create background image and stores in background.
        Temperature temperature;

};

#endif // SCORE_H
