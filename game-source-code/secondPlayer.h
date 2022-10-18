#ifndef SECONDPLAYER_H
#define SECONDPLAYER_H

#include "player.h"
#include "igloo.h"
#include "score.h"

class SecondPlayer : public Player
{
    public:
        SecondPlayer();
        virtual ~SecondPlayer();
        void processEvents(sf::Keyboard::Key key, bool checkPressed, bool gameFinished=false);
        Igloo igloo = Igloo(true);
        Score score;
    protected:

    private:
};

#endif // SECONDPLAYER_H
