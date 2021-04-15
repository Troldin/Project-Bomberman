

#include "Game.h"
#include <Windows.h>

int main()
{

	auto& game = Game::Instance();

	game.Run();

	return 0;
}