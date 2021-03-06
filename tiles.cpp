#include "tiles.h"

using namespace sf;

Tile::Tile(int x,int y,int area)
{
    screen_x = x;
    screen_y = y;
    tile_width = screen_x / 4;
    tile_length = tile_width / 0.618;
    area = area;
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

void Tile::ReSize(Vector2u screen)
{
    screen_x = screen.x;
    screen_y = screen.y;
    tile_width = screen_x / 4;
    tile_length = tile_width / 0.618;
    t.setSize(Vector2f((float)tile_width,(float)tile_length));
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
    t.setPosition(position);
}

int Tile::Drop()
{
    float time,time_exchanged,speed;
    time = 144;
    //time_exchanged = time * 100000;
    speed = screen_y / time;
    t.move(0.f,speed);
    //t.setFillColor(Color::Black);
    usleep(7500);
    position = t.getPosition();
    if(position.y > screen_y)
        return 1;
    else
        return 0;
}

bool Tile::IsHit()
{
    sf::Vector2i MousePosition = sf::Mouse::getPosition();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && IsActive == false)
    {
        if(MousePosition.x >= position.x && MousePosition.x <= position.x + tile_width)
        {
            if(MousePosition.y >= position.y && MousePosition.y <= position.y + tile_length)
            {
                hitposition = position;
                t.setFillColor(sf::Color(0,0,0,70));
                sf::Vector2i MousePosition(NULL,NULL);
                IsActive = true;
                return true;
            }
        }
    }
}

HitTile::HitTile(int x,int y,Vector2f pos)
{
    screen_x = x;
    screen_y = y;
    tile_width = screen_x / 4;
    tile_length = tile_width / 0.618;
    t.setSize(Vector2f((float)tile_width,(float)tile_length));
    t.setFillColor(sf::Color(0,0,0,70));
    t.setPosition(pos);
}

int HitTile::Drop()
{
    float time,time_exchanged,speed;
    time = 144;
    //time_exchanged = time * 100000;
    speed = screen_y / time;
    t.move(0.f,speed);
    //t.setFillColor(Color::Black);
    usleep(7500);
    position = t.getPosition();
    if(position.y > screen_y)
        return 1;
    else
        return 0;
}
