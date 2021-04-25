#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "tiles.h"

sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Black White Tiles");
sf::Font font;

int main()
{
    int Score = 0;
    char ScoreChar[100];
    String ScoreString;
    sf::Vector2u screen = window.getSize();
    font.loadFromFile("font.ttf");
    sf::Text score;
    score.setFillColor(sf::Color::Green);
    score.setFont(font);
    score.setPosition(0,0);
    srand((unsigned)time(NULL));
    int area = rand()%5;
    while(area == 0)
    {
        area = rand()%5;
    }
    Tile *tile = new Tile(screen.x,screen.y,area);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Resized)
                screen = window.getSize();
            if (event.type == sf::Event::Closed)
                window.close();
        }
        score.setCharacterSize(screen.x / 8);
        window.clear(sf::Color::White);
        tile->Drop();
        tile->IsHit();
        sprintf(ScoreChar,"%d",Score);
        ScoreString = ScoreChar;
        score.setString(sf::String(ScoreString));
        window.draw(tile->t);
        window.draw(score);
        window.display();
        if(tile->Drop() == 1)
        {
            area = rand()%5;
            while(area == 0)
            {
                area = rand()%5;
            }
            tile = new Tile(screen.x,screen.y,area);
        }
        if(tile->IsHit() == 1)
        {
            Score++;
        }
    }

    return 0;
}
