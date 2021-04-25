#include "tiles.h"

using namespace sf;

Tile::Tile(int x,int y,int area)
{
    screen_x = x;
    screen_y = y;
    tile_width = screen_x / 4;
    tile_length = tile_width / 0.618;
    //RectangleShape t(sf::Vector2f(tile_x, tile_y));
    t.setSize(Vector2f((float)tile_width,(float)tile_length));
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
    float time,time_exchanged,speed;
    time = 4;
    time_exchanged = time * 100000;
    speed = screen_y / time;
    t.move(0.f,speed);
    //t.setFillColor(Color::Black);
    usleep(time_exchanged);
    position = t.getPosition();
    if(position.y > screen_y)
        return 1;
}

int Tile::IsHit()
{
    sf::Vector2i MousePosition = sf::Mouse::getPosition();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(MousePosition.x >= position.x && MousePosition.x <= position.x + tile_width)
        {
            if(MousePosition.y >= position.y && MousePosition.y <= position.y + tile_length)
            {
                t.setFillColor(sf::Color(0,0,0,75));
                return 1;
            }
        }
    }
}
