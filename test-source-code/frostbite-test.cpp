#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/game.h"
#include "../game-source-code/player.h"
#include "../game-source-code/ice.h"

TEST_CASE("Testing the game window")
{
    Game game = Game();
    CHECK(game.window.isOpen());  //Checking if game window is open.
    CHECK(game.window.getSize().x == 800);   //Check the width is 800.
    CHECK(game.window.getSize().y == 540);   //Check the height is 540.
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
    player.processEvents(sf::Keyboard::Right, true);    //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                                //Move the player
    CHECK(player.getXPosition()==305);                  //Check the new position is as expected

    player.processEvents(sf::Keyboard::Left, true);     //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                                //Move the player
    CHECK(player.getXPosition()==300);                  //Check the new position is as expected
}

TEST_CASE("Testing Player Down movement")
{
    Player player;                                   //Player object
    player.processEvents(sf::Keyboard::Down, true);  //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                             //Move the player
    CHECK(player.getYPosition()==165);               //Check the new position is as expected
}

TEST_CASE("Testing Player Upwards movement")
{
    Player player;                                  //Player object
    player.processEvents(sf::Keyboard::Up, true);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                            //Move the player
    CHECK(player.getYPosition()==155);              //Check the new position is as expected
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
