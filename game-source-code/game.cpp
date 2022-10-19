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

void Game::loadSecondPlayer()
{
    secondPlayer.resetPlayer(true);
    stage2 = 0;
    iceLevels.twoPlayers();//
    iceLevels.resetActive(true,true);//
}
void Game::resetGame()
{
    alive = true;
    player.resetPlayer(true); //Reset the players properties.
    if(start==2){secondPlayer.resetPlayer(true);};//
    if(start==2){secondPlayer.score.resetScore();};//
    score.resetScore();
    iceLevels.resetActive(true);
    scoreIncrement=10;
    levelNumber=1;
    levelText.setString(to_string(levelNumber));
    stage=0;
    temperature.resetTemperature();
    enemyGenerator.resetEnemies();
    iceLevels.changeDirection(true);
    iceLevels.onePlayer();//
}

void Game::playGame()
{
    if(!start){return;};                                                //Check that user wants to play.
    window.setFramerateLimit(60);                                              //reset the score.
    while(window.isOpen())                                              //Loop as long as window is open
    {
        if(player.getLives()<0 && secondPlayer.getLives()<0)                                         //if the player loses the game and has no lives, return to the splash screen.
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
                else if(event.key.code==sf::Keyboard::Space && stage>0 && player.getLanded()){iceLevels.changeDirection(false,player.getYPosition());stage-=((stage!=16 && stage>0));}
                else if(start == 2 && event.key.code==sf::Keyboard::Tab && stage2>0 && secondPlayer.getLanded()){iceLevels.changeDirection(false,secondPlayer.getYPosition());stage2-=((stage2!=16 && stage2>0));}
                else
                {
                    player.processEvents(event.key.code,true, finished);              //process the event.
                    if(start==2){secondPlayer.processEvents(event.key.code,true, finished2);};//
                }
            }
            if(event.type ==sf::Event::KeyReleased)                     //If the key is released,
            {
                player.processEvents(event.key.code,false, finished);             //process the release.
                if(start==2){secondPlayer.processEvents(event.key.code,false, finished2);};//
            }
        }
        window.clear(sf::Color(1,25,125));                            //clear the background of the window background color.
        window.draw(background);                                        //draw the background sprite.
        gameLogic();
        if(start==2){secondPlayer.igloo.drawIgloo(window,stage2);};//
        if(start==2){secondPlayer.score.drawScore(window);};//
        igloo.drawIgloo(window, stage);                                 //draw the current stage of the igloo.
        score.drawScore(window);                                        //display the score.
        window.draw(levelText);                                         //draw the current level number.
        frameShown++;
        window.display();                                               //Display the current frame.
    }
}

void Game::gameLogic()
{
    processIceLevels();
    processPlayer();
    processTemperature();
    processEnemies();
    finished = int(stage/16);                                       //if the player has collected 16 ice blocks, he is 'finished' and can win the game.
    finished2 = int(stage2/16);
}
void Game::processIceLevels()
{
    iceLevels.movePosition();                                       //move the iceBlocks.
    iceLevels.drawInWindow(window);                                 //draw the iceBlocks.
}
void Game::processPlayer()
{
    alive = player.checkDeath();                                    //check if the player has died, by falling into water.
    player.movePlayer(enemyGenerator.findCollision(player));                 //move the player, pass in whether he is collided with an enemy.
    if(player.getGameWon()){finishGame();};                         //if the player has won the game and entered the igloo, process the animations.
    player.drawInWindow(window);                                    // draw the player.
    player.drawLives(window);                                       //draw the lives remaining
    checkLanded();                                                  //check if the player has landed on the blocks.

    if(start!=2){return;};
    alive = secondPlayer.checkDeath();                                    //check if the player has died, by falling into water.
    secondPlayer.movePlayer(enemyGenerator.findCollision(secondPlayer));                 //move the player, pass in whether he is collided with an enemy.
    if(secondPlayer.getGameWon()){finishGame();};                         //if the player has won the game and entered the igloo, process the animations.
    secondPlayer.drawInWindow(window);                                    // draw the player.
    secondPlayer.drawLives(window);                                       //draw the lives remaining
    checkLanded2();
    iceLevels.processSprite(0);
}
void Game::processTemperature()
{
    if(temperature.getTimeRemaining()<=0){player.freezeDeath();alive=false;secondPlayer.freezeDeath();}    //if the temperature is below 0, the player freezes and dies.
    temperature.drawTemperature(window, alive);                     //display the temperatu//
}
void Game::processEnemies()
{
    enemyGenerator.drawInWindow(window,frameShown);                          //draw and animate the enemies movement.
    bool prob = (enemyWeighting==(rand()%enemyWeighting+1));
    if(prob){enemyGenerator.generateEnemy(-1);};
    enemyGenerator.movePosition();                                           //move the enemies
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
        //score.changeScore((stage<16&&initialLanding)*scoreIncrement);             //increase the players score
        //if(initialLanding&&stage<16){stage++;};                                   //add an extra piece to the igloo
        if(initialLanding&&stage<16){iceLevels.setActive(state);stage++;score.changeScore(scoreIncrement);};
    }
    else
    {
        player.setLanded(false);                                                  //Otherwise set the landed state to false.
        player.setFloorMomentum(0);                                               // set his floor momentum to 0;
    }
}
void Game::checkLanded2()                                                          //Check for whether the player landed on an Ice block.
{
    if(!secondPlayer.getGrounded()){secondPlayer.setLanded(false); secondPlayer.setFloorMomentum(0);iceLevels.resetActive(false, true);return;};//only check when on the ground.
    int state = (iceLevels.findCollision(secondPlayer.getXPosition(), secondPlayer.getYPosition(), secondPlayer, true));
    if(state>=0)                                                                  //Search for a collision of the players position within iceLevels.
    {
        secondPlayer.setLanded(true);                                                   //If there is a collision, set the landed state to true.
        secondPlayer.setFloorMomentum(iceLevels.getMomentumOfRow(state));               // add the momentum of the floor to the players.
        bool initialLanding = (!iceLevels.getActive2(state));                      //If first time landed on block
        if(initialLanding&&stage2<16){iceLevels.setActive2(state);stage2++;secondPlayer.score.changeScore(scoreIncrement);};
    }
    else
    {
        secondPlayer.setLanded(false);                                                  //Otherwise set the landed state to false.
        secondPlayer.setFloorMomentum(0);                                               // set his floor momentum to 0;
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
    scoreIncrement+=((levelNumber<=10)*10);                                                                     //each level the points per block is increased by 10.
    temperature.resetTemperature();                                                         //reset the temperature for the new level.
    player.resetPlayer(false);                                                                   //reset the players state for the new level.
    iceLevels.resetActive(true);
    enemyWeighting-=((levelNumber<=4)*50);
}
