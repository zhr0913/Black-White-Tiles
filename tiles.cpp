#include "tiles.h"
#include <unistd.h>

using namespace sf;

Tile::Tile(int x,int y)
{
    screen_x = x;
    screen_y = y;
    tile_x = screen_x / 4;
    tile_y = tile_x * 2;
    //RectangleShape t(sf::Vector2f(tile_x, tile_y));
    t.setSize(sf::Vector2f(tile_x, tile_y));
    t.setFillColor(Color::Black);
    t.setPosition(Vector2f(0,0));
}

void Tile::Drop()
{
    int y = 0;
    for(int y = 0; y < screen_y;y = y + 5)
    {
        t.move(Vector2f(0,y));
        usleep(5000);
    }
}
