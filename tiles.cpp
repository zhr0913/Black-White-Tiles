#include "tiles.h"
#include <unistd.h>

using namespace sf;

Tile::Tile(int x,int y,int area)
{
    screen_x = x;
    screen_y = y;
    tile_width = screen_x / 4;
    tile_length = tile_width * 2;
    //RectangleShape t(sf::Vector2f(tile_x, tile_y));
    t.setSize(Vector2f(tile_width, tile_length));
    t.setFillColor(Color::Black);
    Vector2f position;
    if(area == 1)
    {
        position.x = 0.f;
        position.y = 0.f - (float)tile_length;
    }
    else if(area == 2)
    {
        position.x = 0.f + (float)tile_width;
        position.y = 0.f - (float)tile_length;
    }
    else if(area == 3)
    {
        position.x = 0.f + (float)tile_width * 2;
        position.y = 0.f - (float)tile_length;
    }
    else if(area == 4)
    {
        position.x = 0.f + (float)tile_width * 3;
        position.y = 0.f - (float)tile_length;
    }
    //position = t.getPosition();
    t.setPosition(position);
}

Tile::~Tile()
{

}

int Tile::Drop()
{
    t.move(0.f,10.f);
    //t.setFillColor(Color::Black);
    usleep(25000);
    position = t.getPosition();
    if(position.y > screen_y)
        return 1;
}
