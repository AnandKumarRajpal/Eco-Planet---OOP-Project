#include "Game.hpp"
#include <time.h>
#include <SDL.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

Game *game = NULL;

int main(int argc, char *args[])
{
    srand(time(0));
    game = new Game("ECO PLANET", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 500, false);
    game->LoadMedia();
    game->init();
    game->gameLoop();
    // while (game->running())
    // {
    //     game->Render();
    //     game->handlEvents();
    //     game->Update();
    //     //game->Render();
    //     //break;
    // }
    game->Clean();
    return 0;
}