#ifndef ICELEVELS_H
#define ICELEVELS_H
#include <vector>
#include "iceRow.h"
#include <SFML/Audio.hpp>
/**
*@brief IceLevels Class
* that uses composition to control the logic and structure of the iceRows present.
*@authors Gilad Kangisser (2367017)
*@authors Natan Grayman (2344104)
*/
class IceLevels
{
    public:
        /**
        *@brief Default Constructor that populates the the  iceLevels with 4 individual IceRows and initializes the variable to store the velocity that the Ice will move at.
        */
        IceLevels();
        /**
        *@brief Default Destructor
        */
        virtual ~IceLevels();
        /**
        *@brief Function to render each Ice to the window.
        *@param window indicates the game window where the object must be displayed.
        */
        void drawInWindow(sf::RenderWindow &window); // render each Ice in the window.
         /**
        *@brief Function to move the current IceRow to its new positions.
        */
        void movePosition(); //move all Ice blocks.
        /**
        * @brief Function to load the texture for each element of Ice.
        * @param string name specifies the image for each Ice object.
        */
        void loadTexture(string name); //load the texture for each element of Ice.
        /**
        * @brief Function to load the texture for a specific row of Ice.
        * @param string name specifies the image for each Ice object.
        * @param int rowNum specifies the level index.
        */
        void loadOneRowTexture( string name, int rowNum); //load the texture for a specific row of Ice.
        /**
        *@brief Function to search for a collision of each Ice block with inputted co-ordinates.
        * @param float x which is used to see if the horizontal co-ordinates are contained within the bounded rectangle of collison.
        * @param float y which is used to check if the vertical co-ordinates are contained within the bounded rectangle of collison.
        * @param Entity entity used to find the collision between the bounding box of respective entity.
        * @param bool secondP which refers to second player mode and is false as default.
        * @return Returns true if a collision is found, otherwise false.
        */
        int findCollision(float x, float y, Entity entity, bool secondP=false);
        /**
        * @brief Function to reset the state of each row of iceBlocks.
        * @param bool initial specifies the ice has not been landed on by the first player and therefore false as default.
        * @param bool secondary signifies the ice has not been landed on by the seond player and therefore false as default.
        */
        void resetActive(bool initial=false, bool secondary=false);
        /**
        * @brief Getter Function to return whether the respective row is in an active state for Player 1.
        * @param int n represents the specific row.
        * @return Return whether specified row is activated.
        */
        bool getActive(int n){return activated[n];};
        /**
        * @brief Setter Function to set the respective row as active for Player 1.
        * @param int n represents the specific row.
        */
        void setActive(int n){activated[n]=true;};
        /**
        * @brief Getter Function to return whether the respective row is in an active state for Player 2.
        * @param int n represents the specific row.
        * @return Return whether specified row is activated.
        */
        bool getActive2(int n){return activated2[n];};
        /**
        * @brief Setter Function to set the respective row as active for Player 2.
        * @param int n represents the specific row.
        */
        void setActive2(int n){activated2[n]=true;};
        /**
        * @brief  Getter Function to return the respective momentum of specified iceRow.
        * @param int rowNumber indicates the particular IceRow.
        * @return Return the respective momentum of specified iceRow.
        */
        int getMomentumOfRow(int rowNumber){return iceLevels[rowNumber].getMomentum();};
        /**
        * @brief Function which goes to the specified level and given no reset changes its direction.
        * @param bool resetRows allows to force reset the row states.
        * @param float yPos controls the row number with default value of 0.
        */
        void changeDirection(bool resetRows, float yPos=0);
        /**
        * @brief Function which sets the amount of players to two for specific settings.
        */
        void twoPlayers(){players=2;};//
        /**
        * @brief Function which sets the amount of players to one for specific settings.
        */
        void onePlayer(){players=1;};//
        /**
        * @brief Function to load the appropriate image depending on the states for Two player game mode.
        */
        void processSprite(int j);
    protected:

    private:
        vector<IceRow> iceLevels; //create a vector of IceRow objects to form the IceLevels.
        vector<bool> activated{0,0,0,0};
        vector<bool> activated2{1,1,1,1};
        sf::SoundBuffer buffer;
        sf::Sound iceBreak;
        int players;
};

#endif // ICELEVELS_H
