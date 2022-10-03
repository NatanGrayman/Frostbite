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
        //sf::Texture iceTexture;     //Create a texture for iceBlock
        void loadAllTextures();
        void checkLanded();
        //
        int score=0;
        sf::Font scoreFont;
        sf::Text scoreText;
        void loadFont();
        void displayScore();
};
#endif // GAME_H
