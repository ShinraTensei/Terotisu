#include "Game.hpp"

int main()
{
		//Initialize SDL
		if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cout << "Error inizializing SDL2!: " << SDL_GetError() << std::endl;
			return 1;
		}

		Game g(800, 600, "Terotisu");
		while(g.Run())
		{

			g.Update();
		}

		g.Clean();
		return 0;
}
