#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include "player.h"
#include "ice.h"
#include "iceRow.h"
#include "iceLevels.h"
#include <string>
#include "igloo.h"
#include "score.h"
#include "temperature.h"
class Game
{
    public:
        Game(); //Game constructor
        sf::RenderWindow window{sf::VideoMode(800, 540), "FrostBite"}; //Game window
        void playGame();
        void splashScreen();
    private:
        bool start = false;
        int width=800; //Set initial width.
        int height=540; //Set initial height.
        sf::Sprite background; //Sprite initalised to hold the background.
        sf::RenderTexture backgroundTexture; //Create RenderTexture to store background
        void createBackground(); //create background image and stores in background.
        Player player;           //Create player object
        sf::Texture baileyTexture;  //Create Bailey as a texture
        IceLevels iceLevels;         //Pass in the initial velocity to the iceblock
        void loadAllTextures();
        void checkLanded();
        Igloo igloo;
        Score score;
        int stage=0;
        bool finished = false;
        Temperature temperature;
        bool alive;
        sf::Font textFont;
        sf::Text levelText;
};
#endif // GAME_H
