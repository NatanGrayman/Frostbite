#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "game.h"
#include "player.h"
#include <time.h>
#include "screen.h"
int main()
{
    srand(time(0));

    Screen screen;
    screen.splashScreen();
    screen.playGame();
    return 0;
}
