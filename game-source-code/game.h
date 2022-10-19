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
#include "enemy.h"
#include "enemyGenerator.h"
#include "secondPlayer.h"
class Game
{
    public:
        Game(); //Game constructor
        sf::RenderWindow window{sf::VideoMode(800, 540), "FrostBite"}; //Game window
        void playGame();
        void splashScreen();
    private:
        int width=800; //Set initial width.
        int height=540; //Set initial height.
        int start = false;//
        int stage=0;
        bool finished = false; //is game over.
        bool alive; //is player dead
        int scoreIncrement=10;
        int levelNumber=1;
        int enemyWeighting = 250;
        int frameShown = 0;                                               //variable to store how many frames have been shown, allows animations.

        sf::Sprite background; //Sprite initalised to hold the background.
        sf::RenderTexture backgroundTexture; //Create RenderTexture to store background
        sf::Font textFont;
        sf::Text levelText;

        Player player;           //Create player object
        IceLevels iceLevels;         //Pass in the initial velocity to the iceblock
        Igloo igloo;
        Score score;
        Temperature temperature;
        EnemyGenerator enemyGenerator;

        SecondPlayer secondPlayer;
        void loadSecondPlayer();
        void checkLanded2();
        int stage2=0;
        bool finished2=false;

        void createBackground(); //create background image and stores in background.
        void loadLevelFont();
        void loadAllTextures();     //At the start of the game, all Textures are loaded
        void loadFont();
        void gameLogic();
        void processIceLevels();
        void processPlayer();
        void processTemperature();
        void processEnemies();
        void checkLanded();
        void finishGame();
        void resetGame();
};
#endif // GAME_H
