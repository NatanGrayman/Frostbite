#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/game.h"
#include "../game-source-code/player.h"
#include "../game-source-code/ice.h"
#include "../game-source-code/icerow.h"

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
    player.processEvents(sf::Keyboard::Right, true,false);    //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                                //Move the player
    CHECK(player.getXPosition()==305);                  //Check the new position is as expected

    player.processEvents(sf::Keyboard::Left, true,false);     //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                                //Move the player
    CHECK(player.getXPosition()==332);                  //Check the new position is as expected
}

TEST_CASE("Testing Player Down movement")
{
    Player player;                                   //Player object
    player.processEvents(sf::Keyboard::Down, true,false);  //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                             //Move the player
    CHECK(player.getYPosition()==165);               //Check the new position is as expected
}

TEST_CASE("Testing Player Upwards movement")
{
    Player player(300,200);                                  //Player object
    player.processEvents(sf::Keyboard::Up, true,false);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                            //Move the player
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
    player.movePlayer();                            //Move the player
    CHECK(player.getYPosition()==160);              //Check at same max vertical position, due to boundary.

    Player player2(300,440);
    player2.processEvents(sf::Keyboard::Down, true,false);  //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player2.movePlayer();                             //Move the player.
    CHECK(player2.getYPosition()==440);              //Check at same minumum vertical position, due to boundary.
}

TEST_CASE("Testing Player Horizontal Boundary")
{
    Player player(800-32,160);                         //Set at rightmost xPosition (window width-bailey width).
    player.processEvents(sf::Keyboard::Right, true,false);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player.movePlayer();                               //Move the player
    CHECK(player.getXPosition()==800-32);              //Check at same rightmost horizontal position, due to boundary.

    Player player2(0,160);                             //Set at leftmost xPosition.
    player2.processEvents(sf::Keyboard::Left, true,false);   //Pass into processEvents loops the specific testing movement and simulating as pressed.
    player2.movePlayer();                               //Move the player
    CHECK(player2.getXPosition()==27);                  //Check at same leftmost horizontal position, due to boundary.
}
TEST_CASE("Checking collisions")
{
    Player player(300,440);                                  //Move the player to position for testing purposes
    Ice ice(2);                                              //Create ice and set a speed.
    ice.changePosition(300,440);                             //Set position, taking into account bailey's height,width.
    player.movePlayer();
    CHECK(ice.getBounds()==player.getBounds());
    //CHECK(ice.findCollision(player.getXPosition(), player.getYPosition(), player));  //Check collision is true.
}
/*TEST_CASE("Checking collision in the iceRow")
{
    IceRow icerow(465,2);    //Set the icerow position
    Player player(0,440);    //Move the player to where the icerow occurs
    CHECK(icerow.findCollision(player.getXPosition(), player.getYPosition(), player));  //Check collision is true.
} */

