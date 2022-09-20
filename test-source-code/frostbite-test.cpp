#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/game.h"

TEST_CASE("Testing the game window")
{
    Game game = Game();
    CHECK(game.window.isOpen());
    CHECK(game.window.getSize().x == 800);
    CHECK(game.window.getSize().y == 540);
}
