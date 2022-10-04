#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Score
{
    public:
        Score();
        virtual ~Score();
        void drawScore(sf::RenderWindow& window);
        void loadFont();
        void changeScore(int difference){scoreCount+=difference;};
    protected:

    private:
        int scoreCount=0;
        sf::Font scoreFont;
        sf::Text scoreText;
};

#endif // SCORE_H
