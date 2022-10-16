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
            if(event.key.code == sf::Keyboard::Enter)                     //If the enter key is pressed,
            {
                start = 1;                                          //The game can now start
                createBackground();                                // Build the Background sprite.
                loadAllTextures();                                 //Load all the textures
                resetGame();
                return;                                            //End the test.
            }
            else if(event.key.code==sf::Keyboard::T)
            {

            }
        }
    }
}

void Screen::loadAllTextures()
{

}

void Screen::playGame()
{

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

void Screen::finishGame()
{

}

void Screen::resetGame()
{

}
