#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <SFML/Audio.hpp>

/**
*@brief Player Class
*A type of Entity descendant that models the player throughout the runtime of the game/s.
*/
class Player : public Entity
{
    public:
        /**@brief Default Constuctor
        *takes in no arguments and sets the initial co-ordinates of the player to the start point. As well as resetting member
        *variables.
        */
        Player();   //Constructor
        /**@brief Overloaded Constructor
        *that creates a Player object at a specified position.
        *@param float xInitial refers to the initial x position of the Player.
        *@param float yInitial refers to the initial y position of the Player.
        */
        Player(float xInitial, float yInitial);
        virtual ~Player();  //Destructor
        /**
        *@brief Function to load an image to the Player.
        *@param name is the relative path of the image that is being loaded.
        */
        void loadTexture(string name);
        /**
        *@brief  Function to load the font of the text that displays the players lives.
        *@param secondary denotes whether it is the lives of the second player which will cause a positional shift of the text.
        */
        void loadFont(bool secondary = false);
        /**
        *@brief Function to process an input by the player, so that the relevant movement can be completed.
        *@param key object that represents the input key.
        *@param checkPressed boolean that indicates whether the key has been pressed or released.
        *@param gameFinished boolean that informs whether the player has collected enough ice and can now enter the igloo.
        */
        void processEvents(sf::Keyboard::Key key, bool checkPressed, bool gameFinished);  //Member function to act on user input
        /**
        *@brief  process the movement of the player over 1 frame.
        *@param enemyVelocity is used to account for any collisions that the player has had with Enemy Entities.
        */
        void movePlayer(int enemyVelocity);    //Member function to move the position of the player.
        /**
        *@brief  Function to draw the remaining lives of the Player.
        *@param window indicates the game window where the object must be displayed.
        */
        void drawLives(sf::RenderWindow& window);
        /**
        *@brief  Function to subtract the players lives and reset his position when the temperature hits 0.
        */
        void freezeDeath();
        /**
        *@brief  Function to check whether the player has died by coming into contact with the water.
        *@return return the state of the player's death.
        */
        bool checkDeath();
        /**
        *@brief  Function to reset the Player member variables and states.
        *@param life boolean is used to signal whether the Player lives should also be reset or not.
        */
        void resetPlayer(bool life);
        /**
        *@brief  Getter function that returns the remaining lives of the Player.
        *@return The remaining lives of the Player.
        */
        int getLives(){return lives;};
        /**
        *@brief  Getter function that returns whether the Player has Won the game or not.
        *@return gameWon boolean.
        */
        bool getGameWon(){return gameWon;};
        /**
        *@brief  Setter function that sets the state of the player on an Ice Block.
        *@param State boolean that will be assigned to landed.
        */
        void setLanded(bool state){landed=state;};
        /**
        *@brief  Getter function that returns whether the Player has Landed -on an Ice Block.
        *@return The Player's Landing status.
        */
        bool getLanded(){return landed;};
        /**
        *@brief  Setter function that sets the momentum of the floor that the player is standing on to retain its motion.
        *@param x float that will be assigned to the floorMomentum of the Player.
        */
        void setFloorMomentum(float x){floorMomentum=x;};
        /**
        *@brief  Getter function that returns whether the player is busy jumping or not.
        *@return Returns whether the Player is grounded - on Ice or SafeZone.
        */
        bool getGrounded(){return grounded;};
    protected:

        void checkXBoundary();    //Function to check not out of bounds in horizontal direction
        void checkYBoundary();    //Function to check not out of bounds in vertical direction
        void finishGame();
        bool grounded;     //grounded as a boolean to know if in air vs ground
        int ticks;         //ticks to count jumping time.
        bool landed;              //Variable that stores the state of whether the player has landed on an Ice block.
        float floorMomentum=0;    //Momentum of the floor that the player stands on to adjust momentum to that.
        int lives;
        bool rightFacing = true;
        bool gameWon = false;
        int animated = 0;
        sf::Font playerFont;
        sf::Text playerText;
        sf::SoundBuffer buffer;
        sf::Sound jumpSound;
        sf::Texture texture;
            private:

};

#endif // PLAYER_H
