#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "tiles.h"

sf::Font font;

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Black White Tiles");
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
    int area = rand()%4+1;
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

        sf::RectangleShape line1(sf::Vector2f(1.f,screen.y));
        sf::RectangleShape line2(sf::Vector2f(1.f,screen.y));
        sf::RectangleShape line3(sf::Vector2f(1.f,screen.y));
        line1.setFillColor(sf::Color::Black);
        line2.setFillColor(sf::Color::Black);
        line3.setFillColor(sf::Color::Black);
        line1.setPosition(screen.x / 4 , 0);
        line2.setPosition(screen.x / 4 * 2, 0);
        line3.setPosition(screen.x / 4 * 3,0);

        score.setCharacterSize(screen.x / 8);
        window.clear(sf::Color::White);
        tile->Drop();
        //tile->IsHit();
        sprintf(ScoreChar,"%d",Score);
        ScoreString = ScoreChar;
        score.setString(sf::String(ScoreString));

        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(tile->t);
        window.draw(score);
        window.display();

        if(tile->Drop() == 1)
        {
            area = rand()%4+1;
            tile->~Tile();
            tile = new Tile(screen.x,screen.y,area);
        }
        if(tile->IsHit() == true)
        {
            Score++;
        }
    }

    return 0;
}

