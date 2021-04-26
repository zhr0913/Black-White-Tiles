#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unistd.h>

using namespace sf;

class Tile
{
public:
    Tile(int x,int y,int area);
    ~Tile();
    RectangleShape t;
    int Drop();
    bool IsHit();
    //Sprite st;
private:
    bool IsActive = false;
    int tile_width,tile_length;
    //float tile_x,tile_y;
    Vector2f position;
    int screen_x,screen_y;
};
