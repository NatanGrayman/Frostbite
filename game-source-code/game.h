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
    private:
        void processIceLevels();
        void processPlayer();
        void processTemperature();
        void processEnemies();
        void checkLanded();
        void checkLanded2();//

        bool alive; //is player dead
        int scoreIncrement=10;
        int enemyWeighting = 250;

    protected:
        int start = false;//
        void gameLogic();
        Player player;           //Create player object
        IceLevels iceLevels;         //Pass in the initial velocity to the iceblock
        Igloo igloo;
        Score score;
        Temperature temperature;
        EnemyGenerator enemyGenerator;
        void setupGame();
        int stage=0;
        bool finished = false; //is game over.

        SecondPlayer secondPlayer;
        void setupSecondPlayer();
        int stage2=0;
        bool finished2=false;
};
#endif // GAME_H
