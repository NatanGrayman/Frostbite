#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
    public:
        Game(); //Game constructor
        sf::RenderWindow window{sf::VideoMode(800, 540), "FrostBite"}; //Game window
        void playGame();
    private:
        int width=800; //Set initial width.
        int height=540; //Set initial height.
        sf::Sprite background; //Sprite initalised to hold the background.
        sf::RenderTexture backgroundTexture; //Create RenderTexture to store background
        void createBackground(); //create background image and stores in background.
};
#endif // GAME_H
