#include "game.h"

int main( int argc, char* args[] )
{
    Game *game = new Game();
    if (!game->Initialize()) {
        printf("Game failed to initialize.");
        return -1;
    }

    while( game->running() ) {
        game->Update();
    }

	return 0;
}
