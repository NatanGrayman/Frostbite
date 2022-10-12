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
                resetGame();
                return;                                            //End the test.
            }
        }
    }
}

void Game::loadAllTextures()
{
    player.loadTexture(baileyTexture, "resources/bailey.png");   // add the bailey image as a texture
    player.loadFont();
    iceLevels.loadTexture(/*iceTexture,*/ "resources/iceBlock.png");       //add the ice block image as a texture
    score.loadFont();                                                       //load the scores font.
    temperature.loadFont();                                                 //load the temperature font.
    if(!textFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;};
    levelText.setFont(textFont);
    levelText.setCharacterSize(22);
    levelText.setPosition(sf::Vector2f(50,20));
    levelText.setFillColor(sf::Color(132,148,255));

}

void Game::resetGame()
{
    alive = true;
    player.resetPlayer(true); //Reset the players properties.
    score.resetScore();
    iceLevels.resetActive(true);
    scoreIncrement=10;
    levelNumber=1;
    levelText.setString(to_string(levelNumber));
    stage=0;
}

void Game::playGame()
{
    if(!start){return;};                                                //Check that user wants to play.
    window.setFramerateLimit(60);                                              //reset the score.
    Enemy enemy(215, 2);                                                  //create a row of enemies.
    int frameShown = 0;                                                 //variable to store how many frames have been shown, allows animations.
    while(window.isOpen())                                              //Loop as long as window is open
    {
        if(player.getLives()<0)                                         //if the player loses the game and has no lives, return to the splash screen.
        {
            splashScreen();
        }
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
                else if(event.key.code==sf::Keyboard::Space && player.getLanded()){iceLevels.changeDirection();stage-=(!(stage==16));}
                else
                {
                    player.processEvents(event.key.code,true, finished);              //process the event.
                }
            }
            if(event.type ==sf::Event::KeyReleased)                     //If the key is released,
            {
                player.processEvents(event.key.code,false, finished);             //process the release.
            }
        }
        window.clear(sf::Color(1,25,125));                            //clear the background of the window background color.
        window.draw(background);                                        //draw the background sprite.
        iceLevels.movePosition();                                       //move the iceBlocks.
        iceLevels.drawInWindow(window);                                 //draw the iceBlocks.
        alive = player.checkDeath();                                    //check if the player has died, by falling into water.
        player.movePlayer(enemy.findCollision(player));                 //move the player, pass in whether he is collided with an enemy.
        if(player.getGameWon()){finishGame();};                         //if the player has won the game and entered the igloo, process the animations.
        player.drawInWindow(window);                                    // draw the player.
        player.drawLives(window);                                       //draw the lives remaining
        checkLanded();                                                  //check if the player has landed on the blocks.
        igloo.drawIgloo(window, stage);                                 //draw the current stage of the igloo.
        score.drawScore(window);                                        //display the score.
        finished = int(stage/16);                                       //if the player has collected 16 ice blocks, he is 'finished' and can win the game.
        if(temperature.getTimeRemaining()<=0){player.freezeDeath();alive=false;}    //if the temperature is below 0, the player freezes and dies.
        temperature.drawTemperature(window, alive);                     //display the temperature.
        window.draw(levelText);                                         //draw the current level number.
        enemy.movePosition();                                           //move the enemies
        enemy.drawInWindow(window,frameShown);                          //draw and animate the enemies movement.
        frameShown++;
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
    int state = (iceLevels.findCollision(player.getXPosition(), player.getYPosition(), player));
    if(state>=0)                                                                  //Search for a collision of the players position within iceLevels.
    {
        player.setLanded(true);                                                   //If there is a collision, set the landed state to true.
        player.setFloorMomentum(iceLevels.getMomentumOfRow(state));               // add the momentum of the floor to the players.
        bool initialLanding = (!iceLevels.getActive(state));                      //If first time landed on block
        score.changeScore(initialLanding*scoreIncrement);                         //increase the players score
        if(initialLanding&&stage<16){stage++;};                                   //add an extra piece to the igloo
        iceLevels.setActive(state);
    }
    else
    {
        player.setLanded(false);                                                  //Otherwise set the landed state to false.
        player.setFloorMomentum(0);                                               // set his floor momentum to 0;
    }
}

void Game::finishGame()
{
    int frame=0;                                                //frames used to animate winning process
    const int extraTime = temperature.getTimeRemaining();
    int timeRemaining = extraTime;
    while(stage>0)                                              //Loop as long as window is open
    {
        window.clear(sf::Color(1,25,125));                            //clear the background of the window background color.
        window.draw(background);                                        //draw the background sprite.
        iceLevels.movePosition();
        iceLevels.drawInWindow(window);
        player.drawLives(window);
        timeRemaining-=(((frame%int(160/extraTime))==0)&&timeRemaining>0);                  //decrease the time remaining faster than usual to rundown the clock.
        score.changeScore(scoreIncrement*(((frame%int(160/extraTime))==0)&&timeRemaining>0));//increase the score by each extra second after winning
        temperature.enterIgloo(window, timeRemaining);                                      //display the temperature animation when winning.
        stage-=(frame%10==0);                                                               //decrease the stage to show the igloo disappearing.
        score.changeScore((scoreIncrement*(frame%10==0)));                                  //increase the score for each block of the igloo.
        igloo.drawIgloo(window, stage);
        score.drawScore(window);
        window.draw(levelText);
        window.display();
        frame++;
    }
    levelText.setString(to_string(++levelNumber));                                         //increase the level number showing the next level has started.
    scoreIncrement+=10;                                                                     //each level the points per block is increased by 10.
    temperature.resetTemperature();                                                         //reset the temperature for the new level.
    player.resetPlayer(false);                                                                   //reset the players state for the new level.
    iceLevels.resetActive(true);
}
