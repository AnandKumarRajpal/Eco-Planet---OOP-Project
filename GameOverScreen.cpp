#include "GameOverScreen.hpp"

enum buttonNames
{
    QUIT = 0,
    PLAYAGAIN = 1,
};
GameOverScreen::GameOverScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    totalButtons = 2;
    btns = new Button *[2];
    btns[QUIT] = new Button(1250, 7, 500, 380, 620, 190);
    btns[PLAYAGAIN] = new Button(1251, 195, 200, 380, 620, 190);
    std::cout << "Game Over Screen constructor called" << std::endl;
}
void GameOverScreen::Update() {}
void GameOverScreen::handleEvents(SDL_Event *e)
{
    for (int i = 0; i < totalButtons; ++i)
    {
        btns[i]->handleEvents(e);
        if (btns[i]->inside == true)
        {
            if (btns[i] == btns[PLAYAGAIN])
            {
                switch (e->type)
                {
                    // case SDL_MOUSEMOTION:
                    //     mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    //     break;

                    // case SDL_MOUSEBUTTONDOWN:

                    //     break;

                case SDL_MOUSEBUTTONUP:
                    std::cout << "Main Screen Load" << std::endl;
                    break;
                }
            }
            else if (btns[i] == btns[QUIT])
            {
                SDL_Quit();
            }
        }
    }
}