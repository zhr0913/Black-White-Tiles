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
    void ReSize(Vector2u screen);
    //Sprite st;
    Vector2f position;
    Vector2f hitposition;
private:
    bool IsActive = false;
    int tile_width,tile_length;
    //float tile_x,tile_y;
    int screen_x,screen_y;
    int area;
};

class HitTile
{
public:
    HitTile(int x,int y,Vector2f pos);
    ~HitTile();
    int Drop();
    RectangleShape t;
    Vector2f position;
private:
    int tile_width,tile_length;
    int screen_x,screen_y;
};
