#include "game.h"
#include "Entity.h"
#include "player.h"
#include <iostream>
#include <string>
#include "ice.h"
#include "iceRow.h"
#include "iceLevels.h"
#include <math.h>
using namespace std;

Game::Game()
{
}

void Game::splashScreen()                                       //Function to control splashscreen
{
    sf::Sprite splashSprite;                                    //Create sprite for the splash screen
    sf::Texture splashTexture;                                  //Create texture for the splash screen

    if(!splashTexture.loadFromFile("resources/splashScreen.png"))  //load from file specific splashtexture.
    {
        cout<<"Error in loading texture";                          //Error message if does not load
    }

    splashSprite.setTexture(splashTexture);                       //Set the texture of the sprite.
    float xScale = float(width)/1280;                             //Create the scale of the width to fit the window
    float yScale = float(height)/720;                             //Create the scale of the height to fit the window
    splashSprite.setScale(sf::Vector2f(xScale,yScale));           //Set the scale

    window.clear();
    window.draw(splashSprite);                                     //Draw in the splashsprite
    window.display();
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
            if(event.key.code==sf::Keyboard::Escape){window.close();}
            if(event.key.code == sf::Keyboard::Enter)                     //If the enter key is pressed,
            {
                start = true;                                      //The game can now start
                createBackground();                                // Build the Background sprite.
                loadAllTextures();                                 //Load all the textures
                return;                                            //End the test.
            }
        }
    }
}

void Game::loadAllTextures()
{
    player.loadTexture(baileyTexture, "bailey.png");   // add the bailey image as a texture
    iceLevels.loadTexture(/*iceTexture,*/ "iceBlock.png");       //add the ice block image as a texture
    loadFont();
    loadIgloo();
}

void Game::playGame()
{
    if(!start){return;};                                                //Check that user wants to play.
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
                if(event.key.code==sf::Keyboard::Escape){window.close();}
                else
                {
                    player.processEvents(event.key.code,true);              //process the event.
                }
            }
            if(event.type ==sf::Event::KeyReleased)                     //If the key is released,
            {
                player.processEvents(event.key.code,false);             //process the release.
            }
        }
        window.clear(sf::Color(1,25,125));                            //clear the background of the window background color.
        window.draw(background);                                        //draw the background sprite.
        iceLevels.movePosition();
        iceLevels.drawInWindow(window);
        player.movePlayer();
        player.drawInWindow(window);
        checkLanded();
        drawIgloo();
        scoreText.setString(to_string(score));
        window.draw(scoreText);
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

void Game::checkLanded()                                                          //Check for whether the player landed on an Ice block.
{
    if(!player.getGrounded()){player.setLanded(false); player.setFloorMomentum(0);iceLevels.resetActive();return;};//only check when on the ground.
    int state = (iceLevels.findCollision(player.getXPosition(), player.getYPosition()));
    if(state>=0)                                                                  //Search for a collision of the players position within iceLevels.
    {
        player.setLanded(true);                                                   //If there is a collision, set the landed state to true.
        player.setFloorMomentum(2*pow(-1,state));
        //iceLevels.loadOneRowTexture("landOnIceBlock.png", state);
        bool initialLanding = (!iceLevels.getActive(state));
        score+=(initialLanding*100);
        if(initialLanding&&iglooStage<16){iglooStage++;};
        iceLevels.setActive(state);
    }
    else
    {
        player.setLanded(false);                                                  //Otherwise set the landed state to false.
        player.setFloorMomentum(0);
    }
}

void Game::loadFont()
{
    if(!scoreFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;};
    scoreText.setFont(scoreFont);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Red);
}

void Game::loadIgloo()
{
    for(int i=0;i<12;i++)
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(500+((i%4)*50),120-(int(i/4))*20));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
    for(int j=0;j<2;j++)
    {
        sf::RectangleShape iglooPart(sf::Vector2f(50,20));
        iglooPart.setPosition(sf::Vector2f(550+(50*j),60));
        iglooPart.setFillColor(sf::Color(125,125,125));
        iglooPieces.push_back(iglooPart);
    }
    sf::RectangleShape iglooPart(sf::Vector2f(50,20));
    iglooPart.setPosition(sf::Vector2f(575,40));
    iglooPart.setFillColor(sf::Color(125,125,125));
    iglooPieces.push_back(iglooPart);
    sf::RectangleShape iglooDoor(sf::Vector2f(50,40));
    iglooDoor.setPosition(sf::Vector2f(575,100));
    iglooDoor.setFillColor(sf::Color(0,0,0));
    iglooPieces.push_back(iglooDoor);
}

void Game::drawIgloo()
{
    for(int i=0;i<iglooStage;i++)
    {
        sf::RectangleShape piece = iglooPieces[i];
        window.draw(piece);
    }
}
