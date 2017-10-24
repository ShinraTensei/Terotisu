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
		t.SetPos(30, 30);
		t.SetTexture(TileTex);


		//Game area bounds
		SDL_Rect game_bounds{29, 29, 242, 530};

		while(g.Run())
		{
			//Specify game area
			SDL_SetRenderDrawColor(g.RenPtr, 0, 0, 0, 255);
			SDL_RenderDrawRect(g.RenPtr, &game_bounds);

			//Test
			for(int y = 1; y < 22; y++)
			{
				for(int x = 1; x < 10; x++)
				{
					t.SetPos(30+(x*24), 30+(y*24));
					t.Draw(g.RenPtr);
				}
			}

			t.Draw(g.RenPtr);

			g.Update();
		}

		g.Clean();
		SDL_DestroyTexture(TileTex);
		IMG_Quit();
		return 0;
}
