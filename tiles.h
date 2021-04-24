#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Tile
{
public:
    Tile(int screen_x,int screen_y);
    RectangleShape t;
    void Drop();
    //Sprite st;
private:
    int tile_x,tile_y;
    int screen_x,screen_y;
};
