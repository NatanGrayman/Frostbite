#ifndef SECONDPLAYER_H
#define SECONDPLAYER_H

#include "player.h"
#include "igloo.h"
#include "score.h"
/**
*@brief  secondPlayer
Class to create the second player if chosen, and the extra objects associated with it. IE: the igloo and score.
*/
class SecondPlayer : public Player
{
    public:
        SecondPlayer();
        virtual ~SecondPlayer();
        /**
        *@brief Function to process an input by the player, so that the relevant movement can be completed
        *@param key object that represents the input key
        *@param checkPressed boolean that indicates whether the key has been pressed or released.
        *@param gameFinished boolean that informs whether the player has collected enough ice and can now enter the igloo.
        */
        void processEvents(sf::Keyboard::Key key, bool checkPressed, bool gameFinished=false);
        Igloo igloo = Igloo(true);
        Score score;
    protected:

    private:
};

#endif // SECONDPLAYER_H
