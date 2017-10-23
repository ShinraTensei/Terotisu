#include "Game.hpp"
#include "Tile.hpp"

int main()
{
		//Initialize SDL
		if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cout << "Error inizializing SDL2!: " << SDL_GetError() << std::endl;
			return 1;
		}

		Game g(800, 600, "Terotisu");

		//Shot texture
		SDL_Texture *TileTex = LoadTileTexture(g.RenPtr, "res/tile.png");

		//Test Tile
		Tile t;
		t.SetPos(100, 100);
		t.SetTexture(TileTex);

		while(g.Run())
		{
			t.Draw(g.RenPtr);
			g.Update();
		}

		g.Clean();
		SDL_DestroyTexture(TileTex);
		IMG_Quit();
		return 0;
}
