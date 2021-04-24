#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cstdlib>
#include "tiles.h"

int screen_x = 288;
int screen_y = 512;

sf::RenderWindow window(sf::VideoMode(screen_x, screen_y), "Black White Tiles");

int main()
{
    srand((unsigned)time(NULL));
    int area = rand()%5;
    while(area == 0)
    {
        area = rand()%5;
    }
    Tile *tile = new Tile(screen_x,screen_y,area);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        tile->Drop();
        window.draw(tile->t);
        window.display();
        if(tile->Drop() == 1)
        {
            area = rand()%5;
            while(area == 0)
            {
                area = rand()%5;
            }
            tile = new Tile(screen_x,screen_y,area);
        }
    }

    return 0;
}
