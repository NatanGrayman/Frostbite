#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "game.h"
#include "player.h"
int main()
{
    Game game = Game();
    game.loadAllTextures();
    game.playGame();
    return 0;
}
