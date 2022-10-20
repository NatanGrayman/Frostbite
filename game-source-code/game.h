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
/**
*@brief Game Class
 *that handles the logic of the Game objects.
 *@authors Gilad Kangisser (2367017)
*@authors Natan Grayman (2344104)
*/
class Game
{
    public:

        Game();
    private:
        /**
        *@brief Function to process the movement and logic of the ice blocks.
        */
        void processIceLevels();
        /**
        *@brief Function to process the movement and logic of the player.
        */
        void processPlayer();
        /**
        *@brief Function to process the Game Timer.
        */
        void processTemperature();
        /**
        *@brief Function to process the movement and logic of the enemies.
        */
        void processEnemies();
        /**
        *@brief Function to check whether or not the first player has landed on an ice block and adjusts players states.
        */
        void checkCollisionWithIce();
        /**
        *@brief  Function to check whether or not the second player has landed on an ice block and adjusts players states.
        */
        void checkCollisionWithIce2();//

        bool alive; //is player dead

    protected:
        int start = false;//
        /**
        *@brief  Function to perform the logical operations required in each frame of the game loop
        */
        void gameLogic();
        Player player;           //Create player object
        IceLevels iceLevels;         //Pass in the initial velocity to the iceblock
        Igloo igloo;
        Score score;
        Temperature temperature;
        EnemyGenerator enemyGenerator;
        /**
        *@brief  Function to set initial states of variables and objects, according to the game design.
        */
        void setupGame();
        int stage=0;
        bool finished = false; //is game over.

        int scoreIncrement=10;
        int enemyWeighting = 250;

        SecondPlayer secondPlayer;
        /**
        *@brief  Function to set initial states of variables and objects, according to the possible need of a second player.
        */
        void setupSecondPlayer();
        int stage2=0;
        bool finished2=false;
};
#endif // GAME_H
