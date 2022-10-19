#ifndef ICELEVELS_H
#define ICELEVELS_H
#include <vector>
#include "iceRow.h"
#include <SFML/Audio.hpp>
/**
*@brief IceLevels Class
* that controls the logic and structure of the 4 iceLevels present.
*/
class IceLevels
{
    public:
        /**
        *@brief Default Constructor that populates the the  iceLevels with 4 individual IceRows and initializes the variable to store the velocity that the Ice will move at.
        */
        IceLevels();
        virtual ~IceLevels();
        void drawInWindow(sf::RenderWindow &window); // render each Ice in the window.
        void movePosition(); //move all Ice blocks.
        void loadTexture(/*sf::Texture& texture,*/ string name); //load the texture for each element of Ice.
        void loadOneRowTexture(/*sf::Texture& texture,*/ string name, int rowNum); //load the texture for a specific row of Ice.
        int findCollision(float x, float y, Entity entity, bool secondP=false);
        void resetActive(bool initial=false, bool secondary=false);
        bool getActive(int n){return activated[n];};
        void setActive(int n){activated[n]=true;};
        bool getActive2(int n){return activated2[n];};
        void setActive2(int n){activated2[n]=true;};
        int getMomentumOfRow(int rowNumber){return iceLevels[rowNumber].getMomentum();};
        void changeDirection(bool resetRows, float yPos=0);
        void twoPlayers(){players=2;};//
        void onePlayer(){players=1;};//
        void processSprite(int j);//
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
