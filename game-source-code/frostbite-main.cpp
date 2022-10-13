#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "game.h"
#include "player.h"
#include <time.h>
int main()
{
    srand(time(0));
    Game game;              //Create the game object
    game.splashScreen();    //Display the Splash Screen initially
    game.playGame();        //Play game.

    return 0;
}
