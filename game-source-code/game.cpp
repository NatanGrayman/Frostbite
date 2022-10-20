#include "game.h"
#include "Entity.h"
#include "player.h"
#include <iostream>
#include <string>
#include "ice.h"
#include "iceRow.h"
#include "iceLevels.h"
#include <math.h>

using namespace std;

Game::Game()
{
}

void Game::setupSecondPlayer()
{
    secondPlayer.resetPlayer(true);
    stage2 = 0;
    iceLevels.twoPlayers();//
    iceLevels.resetActive(true,true);//
    secondPlayer.score.resetScore();
}
void Game::setupGame()
{
    alive = true;
    player.resetPlayer(true); //Reset the players properties.
    if(start==2){secondPlayer.resetPlayer(true);};//
    if(start==2){secondPlayer.score.resetScore();};//
    score.resetScore();
    iceLevels.resetActive(true);
    scoreIncrement=10;
    stage=0;
    temperature.resetTemperature();
    enemyGenerator.resetEnemies();
    iceLevels.changeDirection(true);
    iceLevels.onePlayer();//
}

void Game::gameLogic()
{
    processIceLevels();
    processPlayer();
    processTemperature();
    processEnemies();
    finished = int(stage/16);                                       //if the player has collected 16 ice blocks, he is 'finished' and can win the game.
    finished2 = int(stage2/16);
}
void Game::processIceLevels()
{
    iceLevels.movePosition();                                       //move the iceBlocks.
}
void Game::processPlayer()
{
    alive = player.checkDeath();                                    //check if the player has died, by falling into water.
    player.movePlayer(enemyGenerator.findCollision(player));                 //move the player, pass in whether he is collided with an enemy.
    checkCollisionWithIce();                                                  //check if the player has landed on the blocks.

    if(start!=2){return;};
    alive = secondPlayer.checkDeath();                                    //check if the player has died, by falling into water.
    secondPlayer.movePlayer(enemyGenerator.findCollision(secondPlayer));                 //move the player, pass in whether he is collided with an enemy.
    checkCollisionWithIce2();
    iceLevels.processSprite(0);
}
void Game::processTemperature()
{
    if(temperature.getTimeRemaining()<=0){player.freezeDeath();alive=false;secondPlayer.freezeDeath();}    //if the temperature is below 0, the player freezes and dies.
}
void Game::processEnemies()
{
    bool prob = (enemyWeighting==(rand()%enemyWeighting+1));
    if(prob){enemyGenerator.generateEnemy(-1);};
    enemyGenerator.movePosition();                                           //move the enemies
}

void Game::checkCollisionWithIce()                                                          //Check for whether the player landed on an Ice block.
{
    if(!player.getGrounded()){player.setLanded(false); player.setFloorMomentum(0);iceLevels.resetActive();return;};//only check when on the ground.
    int state = (iceLevels.findCollision(player.getXPosition(), player.getYPosition(), player));
    if(state>=0)                                                                  //Search for a collision of the players position within iceLevels.
    {
        player.setLanded(true);                                                   //If there is a collision, set the landed state to true.
        player.setFloorMomentum(iceLevels.getMomentumOfRow(state));               // add the momentum of the floor to the players.
        bool initialLanding = (!iceLevels.getActive(state));                      //If first time landed on block
        if(initialLanding&&stage<16){iceLevels.setActive(state);stage++;score.changeScore(scoreIncrement);};
    }
    else
    {
        player.setLanded(false);                                                  //Otherwise set the landed state to false.
        player.setFloorMomentum(0);                                               // set his floor momentum to 0;
    }
}
void Game::checkCollisionWithIce2()                                                          //Check for whether the player landed on an Ice block.
{
    if(!secondPlayer.getGrounded()){secondPlayer.setLanded(false); secondPlayer.setFloorMomentum(0);iceLevels.resetActive(false, true);return;};//only check when on the ground.
    int state = (iceLevels.findCollision(secondPlayer.getXPosition(), secondPlayer.getYPosition(), secondPlayer, true));
    if(state>=0)                                                                  //Search for a collision of the players position within iceLevels.
    {
        secondPlayer.setLanded(true);                                                   //If there is a collision, set the landed state to true.
        secondPlayer.setFloorMomentum(iceLevels.getMomentumOfRow(state));               // add the momentum of the floor to the players.
        bool initialLanding = (!iceLevels.getActive2(state));                      //If first time landed on block
        if(initialLanding&&stage2<16){iceLevels.setActive2(state);stage2++;secondPlayer.score.changeScore(scoreIncrement);};
    }
    else
    {
        secondPlayer.setLanded(false);                                                  //Otherwise set the landed state to false.
        secondPlayer.setFloorMomentum(0);                                               // set his floor momentum to 0;
    }
}

