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
                createBackground();                                // Build the Background sprite.
                loadAllTextures();                                 //Load all the textures
                loadFont();
                resetGame();
                if(event.key.code ==sf::Keyboard::Num2)
                {
                    loadSecondPlayer();
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
