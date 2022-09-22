#include "game.h"
#include "entity.h"
#include "player.h"
#include <iostream>
#include <string>
#include "ice.h"
using namespace std;

Game::Game()
{
    createBackground();                                // Build the Background sprite.
    ice.changePosition(0, 250);                        //update position of the ice texture
}
void Game::loadAllTextures()
{
    player.loadTexture(baileyTexture, "bailey.png");   // add the bailey image as a texture
    ice.loadTexture(iceTexture, "iceBlock.png");       //add the ice block image as a texture
}

void Game::playGame()
{
    window.setFramerateLimit(60);                                       //Set the frame limit to 60.
    while(window.isOpen())                                              //Loop as long as window is open
    {
        sf::Event event;                                                //Create an event object to monitor for inputs.
        while (window.pollEvent(event))                                 //For each event that occurs.
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();                                        //If the close button is pressed, Close the game window.
            }
            if(event.type == sf::Event::KeyPressed)                     //If a key is pressed,
            {
                player.processEvents(event.key.code,true);              //process the event.
            }
            if(event.type ==sf::Event::KeyReleased)                     //If the key is released,
            {
                player.processEvents(event.key.code,false);             //process the release.
            }
        }
        window.clear(sf::Color(76,109,243));                            //clear the background of the window background color.
        window.draw(background);                                        //draw the background sprite.
        ice.movePosition();
        ice.drawInWindow(window);
        player.movePlayer();
        player.drawInWindow(window);
        window.display();                                               //Display the current frame.
    }
}

void Game::createBackground()                 //Function to create the Background sprite
{
    if (!backgroundTexture.create(width, 210))                                    //Create a texture. with predefined dimensions
        cout<<-1<<endl;

    sf::RectangleShape sky(sf::Vector2f(width, 75));                    //Rectangle shape for the sky
    sf::RectangleShape sunset(sf::Vector2f(width, 35));                 //Rectangle shape for the sunset
    sf::RectangleShape iceLand(sf::Vector2f(width, 100));               //Rectangle shape for the tundra

    sunset.setPosition(sf::Vector2f(0,75));                             //Set the position of the sunset
    iceLand.setPosition(sf::Vector2f(0,110));                           //Set the position of the "iceland"

    sky.setFillColor(sf::Color(45,50,184));                             //Set the color within the "sky".
    sunset.setFillColor(sf::Color(222,159,85));                         //Set the color within the "sunset".
    iceLand.setFillColor(sf::Color(193,192,193));                       //Set the color within the "iceland".

    backgroundTexture.draw(sky);                                                  //Draw the "sky" texture.
    backgroundTexture.draw(sunset);                                               //Draw the "sunset" texture.
    backgroundTexture.draw(iceLand);                                              //Draw the "iceland" texture.
    backgroundTexture.display();                                                  //Display each as a texture.
    background.setTexture(backgroundTexture.getTexture());                        //add background sprite as background
}

