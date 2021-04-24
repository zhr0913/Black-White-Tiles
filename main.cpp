#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "tiles.h"

int screen_x = 288;
int screen_y = 512;

sf::RenderWindow window(sf::VideoMode(screen_x, screen_y), "Black White Tiles");
Tile *tile = new Tile(screen_x,screen_y);

int main()
{

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
    }

    return 0;
}
