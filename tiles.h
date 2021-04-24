#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Tile
{
public:
    Tile(int x,int y,int area);
    ~Tile();
    RectangleShape t;
    int Drop();
    //Sprite st;
private:
    int tile_width,tile_length;
    //float tile_x,tile_y;
    Vector2f position;
    int screen_x,screen_y;
};
