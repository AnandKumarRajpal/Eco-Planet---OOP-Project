#include "StartScreen.hpp"

enum buttonNames
{
    STARTGAME = 0,
    OPTIONS = 1,
    QUIT = 2,
};

StartScreen::StartScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    totalButtons = 3;
    btns = new Button *[3];
    btns[STARTGAME] = new Button(1, 1, 20, 371, 620, 190);
    btns[OPTIONS] = new Button(1, 191, 288, 375, 620, 190);
    btns[QUIT] = new Button(1251, 1, 555, 375, 620, 190);
    std::cout << "Start Screen constructor called" << std::endl;
}
void StartScreen::Update() {}

void StartScreen::handleEvents(SDL_Event *e)
{
    for (int i = 0; i < totalButtons; ++i)
    {
        btns[i]->handleEvents(e);
        if (btns[i]->inside == true)
        {
            if (btns[i] == btns[STARTGAME])
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
StartScreen::~StartScreen()
{
}