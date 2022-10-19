#ifndef SCREEN_H
#define SCREEN_H
#include "game.h"

class Screen: public Game
{
    public:
        Screen();
        virtual ~Screen();
        sf::RenderWindow window{sf::VideoMode(800, 540), "FrostBite"}; //Game window
        void playGame();
        void splashScreen();
    protected:

    private:
        int width=800; //Set initial width.
        int height=540; //Set initial height.
        int frameShown = 0;                                               //variable to store how many frames have been shown, allows animations.
        int levelNumber=1;

        sf::Sprite background; //Sprite initalised to hold the background.
        sf::RenderTexture backgroundTexture; //Create RenderTexture to store background
        sf::Font textFont;
        sf::Text levelText;

        void createBackground(); //create background image and stores in background.
        void loadLevelFont();
        void loadAllTextures();     //At the start of the game, all Textures are loaded
        void loadFont();
        void loadSecondPlayerTextures();

        void drawObjects();
        void finishGame();
};

#endif // SCREEN_H
