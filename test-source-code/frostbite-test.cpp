#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "synchapi.h"
#include "../game-source-code/screen.h"
#include "../game-source-code/game.h"
#include "../game-source-code/player.h"
#include "../game-source-code/ice.h"
#include "../game-source-code/icerow.h"
#include "../game-source-code/igloo.h"
#include "../game-source-code/score.h"
#include "../game-source-code/enemy.h"
#include "../game-source-code/temperature.h"

TEST_CASE("Testing the game window")
{
    Screen screen;
    CHECK(screen.window.isOpen());  //Checking if game window is open.
    CHECK(screen.window.getSize().x == 800);   //Check the width is 800.
    CHECK(screen.window.getSize().y == 540);   //Check the height is 540.
}

TEST_CASE("Testing player initial position")
{
    Player player;
    CHECK(player.getXPosition()==300);  //Checking bailey initial x-coordinate.
    CHECK(player.getYPosition()==160);  //Checking bailey intial y-coordinate.
}

TEST_CASE("Testing Left and Right Movement of Player")
{
    Player player;                                      //Player object
    player.processEvents(sf::Keyboard::Right, true,false);    //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer(false);                                //Move the player
    CHECK(player.getXPosition()==305);                  //Check the new position is as expected

    player.processEvents(sf::Keyboard::Left, true,false);     //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer(false);                                //Move the player
    CHECK(player.getXPosition()==332);                  //Check the new position is as expected
}

TEST_CASE("Testing Player Down movement")
{
    Player player;                                   //Player object
    player.processEvents(sf::Keyboard::Down, true,false);  //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer(false);                             //Move the player
    CHECK(player.getYPosition()==165);               //Check the new position is as expected
}

TEST_CASE("Testing Player Upwards movement")
{
    Player player(300,200);                                  //Player object
    player.processEvents(sf::Keyboard::Up, true,false);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer(false);                            //Move the player
    CHECK(player.getYPosition()==195);              //Check the new position is as expected
}

TEST_CASE("Testing Ice Block Initialization")
{
    Ice ice(2.f);                                   //Create an Ice block with an initial velocity of 2 pixels per frame.
    ice.changePosition(0,250);                      //set the Ice block to a new position.
    CHECK(ice.getXPosition()==0);                   //check that the changePosition function is working by checking the x position.
    CHECK(ice.getYPosition()==250);                 //check that the changePosition function is working by checking the y position.
}

TEST_CASE("Testing Ice Block Movement")
{
    Ice ice(2.f);                                   //Create an Ice block with an initial velocity of 2 pixels per frame.
    ice.changePosition(100,250);                    //set the Ice block to a new position.
    ice.movePosition();                             //simulate 1 frame of the ice movement.
    CHECK(ice.getXPosition()==102);                 //check that the new position of the block is where it should be based on its velocity.
}
TEST_CASE("Testing wrapping of the ice block for rightward movement")
{
    Ice ice(2.f);                                   //Create an Ice block with an initial velocity positive (right) of 2 pixels per frame.
    ice.changePosition(800,250);                    //set the Ice block to a new position.
    ice.movePosition();                             //simulate 1 frame of the ice movement.
    CHECK(ice.getXPosition()==-93);                 //check that the new position of the block is where it should be when wrapping around.
}
TEST_CASE("Testing wrapping of the ice block for leftward movement")
{
    Ice ice(-2.f);                                   //Create an Ice block with an initial velocity negative (left) of 2 pixels per frame.
    ice.changePosition(-95,250);                    //set the Ice block to a new position.
    ice.movePosition();                             //simulate 1 frame of the ice movement.
    CHECK(ice.getXPosition()==798);                 //check that the new position of the block is where it should be when wrapping around.
}

TEST_CASE("Testing Player Vertical Boundary")
{
    Player player(300, 160);                         //Player object initialized at highest position.
    player.processEvents(sf::Keyboard::Up, true,false);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer(false);                            //Move the player
    CHECK(player.getYPosition()==160);              //Check at same max vertical position, due to boundary.

    Player player2(300,440);
    player2.processEvents(sf::Keyboard::Down, true,false);  //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player2.movePlayer(false);                             //Move the player.
    CHECK(player2.getYPosition()==440);              //Check at same minumum vertical position, due to boundary.
}

TEST_CASE("Testing Player Horizontal Boundary")
{
    Player player(800-32,160);                         //Set at rightmost xPosition (window width-bailey width).
    player.processEvents(sf::Keyboard::Right, true,false);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer(false);                               //Move the player
    CHECK(player.getXPosition()==800-32);              //Check at same rightmost horizontal position, due to boundary.

    Player player2(0,160);                             //Set at leftmost xPosition.
    player2.processEvents(sf::Keyboard::Left, true,false);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player2.movePlayer(false);                               //Move the player
    CHECK(player2.getXPosition()==32);                  //Check at same leftmost horizontal position, due to boundary.
}
TEST_CASE("Checking collisions")
{
    Player player(300,440);                                  //Set the player to position for testing purposes.
    player.movePosition();                                   //Move player to that Position.
    Ice ice(2);                                              //Create ice and set a speed.
    sf::Texture iceTexture;
    ice.loadTexture(iceTexture, "resources/iceBlock.png");      //Load both textures, getting their dimensions
    player.loadTexture("resources/bailey.png");
    ice.changePosition(300,440);                             //Set position, taking into account bailey's height,width.
    CHECK(ice.findCollision(player.getXPosition(), player.getYPosition(), player));  //Check collision is true.
}

TEST_CASE("Checking collision in the iceRow")
{
    IceRow iceRow(465,2);    //Set the icerow position
    Player player(0,465);    //Initial position of player to where the icerow occurs
    player.movePosition();   //Move to Bailey's new position
    sf::Texture playerTexture;
    iceRow.loadTexture("resources/iceBlock.png");           //Load both textures, getting their dimensions
    player.loadTexture("resources/bailey.png");
    CHECK(iceRow.findCollision(player.getXPosition(), player.getYPosition(), player));  //Check collision is true.
}
TEST_CASE("Testing enemy movement")
{
    Enemy enemy(215, 2);
    int x = enemy.getMomentum();
    CHECK(x!=0);
}
TEST_CASE("Testing Enemy Collision")
{
    //Enemy enemy(215, 2);          //Set the enemy position.
    EnemyGenerator enemy;
    enemy.generateEnemy(0);

    Player player(0,0);         //Set Player position
    sf::Texture playerTexture;
    player.loadTexture("resources/bailey.png");
    CHECK(enemy.findCollision(player)!=0);         //Check colision.
}
TEST_CASE("Testing Score Functionality")
{
    Score score;                    //Create a score.
    score.changeScore(15);
    CHECK(15==score.getScore());
    score.changeScore(-5);          //Decrement the score.
    CHECK(10==score.getScore());    //Check updated score.
    score.resetScore();             //reset the score.
    CHECK(0==score.getScore());     //Check the reseting functionality.
}

TEST_CASE("Testing Temperature Functionality")
{
    Temperature temperature;                    //Create a temperature.
    Sleep(1000);                                //Set sleeping for 1 second
    CHECK(temperature.getTimeRemaining() == 44);    //Check 1 second has passed
    temperature.resetTemperature();                 //Reset the temperature
    CHECK(temperature.getTimeRemaining()==45);     //Check resetting functionality
}
