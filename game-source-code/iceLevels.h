#ifndef ICELEVELS_H
#define ICELEVELS_H
#include <vector>
#include "iceRow.h"
#include <SFML/Audio.hpp>

class IceLevels
{
    public:
        IceLevels();
        virtual ~IceLevels();
        void drawInWindow(sf::RenderWindow &window); // render each Ice in the window.
        void movePosition(); //move all Ice blocks.
        void loadTexture(/*sf::Texture& texture,*/ string name); //load the texture for each element of Ice.
        void loadOneRowTexture(/*sf::Texture& texture,*/ string name, int rowNum); //load the texture for a specific row of Ice.
        int findCollision(float x, float y, Entity entity);
        void resetActive(bool begin=false);
        bool getActive(int n){return activated[n];};
        void setActive(int n){activated[n]=true;};
        int getMomentumOfRow(int rowNumber){return iceLevels[rowNumber].getMomentum();};
        void changeDirection();
    protected:

    private:
        vector<IceRow> iceLevels; //create a vector of IceRow objects to form the IceLevels.
        vector<bool> activated{0,0,0,0};
        sf::SoundBuffer buffer;
        sf::Sound iceBreak;
};

#endif // ICELEVELS_H
