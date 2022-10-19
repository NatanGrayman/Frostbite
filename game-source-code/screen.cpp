#include "screen.h"

Screen::Screen()
{
    //ctor
}

Screen::~Screen()
{
    //dtor
}

void Screen::splashScreen()                                       //Function to control splashscreen
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
            if(event.key.code == sf::Keyboard::Enter || event.key.code ==sf::Keyboard::Num2)                     //If the enter key is pressed,
            {
                start = 1;                                      //The game can now start
                levelNumber=1;
                createBackground();                                // Build the Background sprite.
                loadAllTextures();                                 //Load all the textures
                loadFont();
                setupGame();//
                if(event.key.code ==sf::Keyboard::Num2)
                {
                    setupSecondPlayer();//
                    loadSecondPlayerTextures();
                    start=2;
                }
                return;                                            //End the test.
            }
        }
    }
}

void Screen::loadAllTextures()
{
    player.loadTexture(/*baileyTexture,*/ "resources/bailey.png");   // add the bailey image as a texture
    iceLevels.loadTexture(/*iceTexture,*/ "resources/iceBlock.png");       //add the ice block image as a texture
}
void Screen::loadLevelFont()
{
    if(!textFont.loadFromFile("resources/ARCADE_N.ttf")){cout<<"cant load font"<<endl;};
    levelText.setFont(textFont);
    levelText.setCharacterSize(22);
    levelText.setPosition(sf::Vector2f(50,20));
    levelText.setFillColor(sf::Color(132,148,255));
    levelNumber=1;
    levelText.setString(to_string(levelNumber));
}
void Screen::loadFont()
{
    player.loadFont();
    score.loadFont();                                                       //load the scores font.
    temperature.loadFont();                                                 //load the temperature font.
    loadLevelFont();
}
void Screen::loadSecondPlayerTextures()
{
    secondPlayer.loadTexture("resources/bailey2.png");//
    secondPlayer.loadFont(true);//
    secondPlayer.score.loadFont(true);//
}

void Screen::playGame()
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
        drawObjects();
        window.draw(levelText);                                         //draw the current level number.
        frameShown++;
        window.display();                                               //Display the current frame.
    }
}

void Screen::createBackground()                 //Function to create the Background sprite
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

void Screen::drawObjects()
{
    iceLevels.drawInWindow(window);                                 //draw the iceBlocks.
    player.drawInWindow(window);                                    // draw the player.
    player.drawLives(window);                                       //draw the lives remaining
    if(start==2){secondPlayer.drawInWindow(window);};                                    // draw the player.
    if(start==2){secondPlayer.drawLives(window);};                                       //draw the lives remaining
    if(player.getGameWon() && start == 1){finishGame();};
    if(player.getGameWon() && start == 2){winScreen(1);};
    if(secondPlayer.getGameWon()){winScreen(2);};
    temperature.drawTemperature(window, player.checkDeath());                     //display the temperature//
    enemyGenerator.drawInWindow(window,frameShown);                          //draw and animate the enemies movement.
}

void Screen::finishGame()
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

void Screen::winScreen(int playerNum)
{
    sf::Sprite winSprite;                                    //Create sprite for the win screen
    sf::Texture winTexture;                                  //Create texture for the win screen

    if(!winTexture.loadFromFile("resources/winScreenPlayer"+to_string(playerNum)+".PNG"))  //load from file specific wintexture.
    {
        cout<<"Error in loading texture";                          //Error message if does not load
    }

    winSprite.setTexture(winTexture);                       //Set the texture of the sprite.
    float xScale = float(width)/1280;                             //Create the scale of the width to fit the window
    float yScale = float(height)/720;                             //Create the scale of the height to fit the window
    winSprite.setScale(sf::Vector2f(xScale,yScale));           //Set the scale

    window.clear();
    window.draw(winSprite);                                     //Draw in the splashsprite
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
            if(event.key.code == sf::Keyboard::G)                     //If the enter key is pressed,
            {
                splashScreen();
                return;                                            //End the test.
            }
        }
    }
}
