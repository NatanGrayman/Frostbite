#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "game.h"
#include "Entity.h"
#include "player.h"
#include "ice.h"
#include "iceRow.h"
#include "iceLevels.h"
#include <string>
#include "igloo.h"
#include "score.h"
#include "temperature.h"
#include "enemy.h"
#include "enemyGenerator.h"

class Screen
{
    public:
        Screen();
        virtual ~Screen();
        sf::RenderWindow window{sf::VideoMode(800, 540), "FrostBite"}; //Game window
        void playGame();
        void splashScreen();
    protected:

    private:
        Game game1;
        Game game2;
        int start = 0;
        int width=800; //Set initial width.
        int height=540; //Set initial height.
        IceLevels iceLevels;         //Pass in the initial velocity to the iceblock
        void loadAllTextures();     //At the start of the game, all Textures are loaded
        sf::Font textFont;
        int levelNumber=1;
        sf::Text levelText;
        void finishGame();
        EnemyGenerator enemyGenerator;
        int enemyWeighting = 250;
        sf::Sprite background; //Sprite initalised to hold the background.
        sf::RenderTexture backgroundTexture; //Create RenderTexture to store background
        void createBackground(); //create background image and stores in background.
        Temperature temperature;
        void resetGame();
};

#endif // SCREEN_H
