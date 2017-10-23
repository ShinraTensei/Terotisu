#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL2/SDL.h>

class Game
{
private:
    SDL_Window *WinPtr;
    int Width;
    int Height;
    std::string Title;

    void handle_error(bool result);
public:
    SDL_Renderer *RenPtr;
    Game(int _Width, int _Height, std::string _Title);
    bool Run();
    void Update();
    void Clean();
};


#endif /* end of include guard: GAME_HPP */
