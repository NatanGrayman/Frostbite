#ifndef ICEROW_H
#define ICEROW_H
#include "Ice.h"
#include <vector>

class IceRow
{
    public:
        IceRow(float level, int iVelocity);
        virtual ~IceRow();
        void drawEachInWindow(sf::RenderWindow &window);
        void movePosition();
        void loadEachTexture(sf::Texture& texture, string name);
    protected:

    private:
        vector<Ice> iceRow;
        int num=3;
};

#endif // ICEROW_H
