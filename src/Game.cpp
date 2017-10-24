#include "Game.hpp"

Game::Game(int _Width, int _Height, std::string _Title)
{
    Width = _Width;
    Height = _Height;
    Title = _Title;
    KeyState = SDL_GetKeyboardState(nullptr);

    //Create Window
    WinPtr = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
    handle_error(WinPtr != nullptr);
    //Create renderer
    RenPtr = SDL_CreateRenderer(WinPtr, -1, SDL_RENDERER_ACCELERATED);
    handle_error(RenPtr != nullptr);
}

bool Game::Run()
{
    SDL_Event event;
    //Poll for events and handle exit
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
            return false;
            break;
            default:;
        }
        if(KeyState[SDL_SCANCODE_ESCAPE]){return false;}
    }
    //Clear screen
    SDL_SetRenderDrawColor(RenPtr, 111, 111, 111, 255);
    SDL_RenderClear(RenPtr);
    return true;
}

void Game::Update()
{
    SDL_RenderPresent(RenPtr);
}

void Game::Clean()
{
    //Muh mumry
    SDL_DestroyRenderer(RenPtr);
    SDL_DestroyWindow(WinPtr);
    SDL_Quit();
}


void Game::handle_error(bool result)
{
    switch (result) {
        case false:
            throw std::runtime_error(SDL_GetError());
        default:;
    }
}
