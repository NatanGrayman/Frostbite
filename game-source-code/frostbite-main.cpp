#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "game.h"
#include "player.h"
int main()
{

    Game game;              //Create the game object
    game.splashScreen();    //Display the Splash Screen initially
    game.playGame();        //Play game.

    return 0;
}
