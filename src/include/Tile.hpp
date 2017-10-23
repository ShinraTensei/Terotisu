#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Texture *LoadTileTexture(SDL_Renderer *RenPtr, std::string path);

class Tile
{
private:
    SDL_Rect bounds;
    SDL_Texture *texture;
public:
    Tile();

    void SetPos(int x, int y);
    void SetTexture(SDL_Texture *tex);
    void Draw(SDL_Renderer *RenPtr);

};

#endif /* end of include guard: TILE_HPP */
