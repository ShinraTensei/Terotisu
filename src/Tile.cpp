#include "Tile.hpp"

Tile::Tile()
{
    bounds = SDL_Rect{0, 0, 24, 24};
}

void Tile::SetPos(int x, int y)
{
    bounds.x = x;
    bounds.y = y;
}

void Tile::SetTexture(SDL_Texture *tex)
{
    texture = tex;
}

void Tile::Draw(SDL_Renderer *RenPtr)
{
    SDL_SetRenderDrawColor(RenPtr, 255, 100, 50, 255);
    SDL_RenderFillRect(RenPtr, &bounds);
    SDL_RenderCopy(RenPtr, texture, nullptr, &bounds);
}

SDL_Texture *LoadTileTexture(SDL_Renderer *RenPtr, std::string path)
{
    SDL_Surface *surface = IMG_Load(path.c_str());
    if(surface == nullptr){std::cout << IMG_GetError() << std::endl;}
    SDL_Texture *texture = SDL_CreateTextureFromSurface(RenPtr, surface);
    SDL_FreeSurface(surface);

    return texture;
}
