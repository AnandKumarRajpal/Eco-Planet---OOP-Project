#include "PauseScreen.hpp"
enum buttonNames
{
    OPTIONS = 0,
    RESUME = 1,
    QUIT = 2,
    SOUND = 3
};
PauseScreen::PauseScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    totalButtons = 4;
    btns = new Button *[3];
    btns[OPTIONS] = new Button(10, 188, 300, 80, 620, 190);
    btns[RESUME] = new Button(10, 368, 300, 180, 620, 190);
    btns[QUIT] = new Button(1251, 1, 300, 280, 620, 190);
    btns[SOUND] = new Button(10, 736, 300, 370, 620, 190);
    std::cout << "Pause Screen constructor called" << std::endl;
}
void PauseScreen::Update() {}

void PauseScreen::handleEvents(SDL_Event *e)
{
    for (int i = 0; i < totalButtons; ++i)
    {
        btns[i]->handleEvents(e);
        if (btns[i]->inside == true)
        {
            if (btns[i] == btns[RESUME])
            {
                switch (e->type)
                {
                    // case SDL_MOUSEMOTION:
                    //     mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    //     break;

                    // case SDL_MOUSEBUTTONDOWN:

                    //     break;

                case SDL_MOUSEBUTTONUP:
                    std::cout << "Main Screen reLoad" << std::endl;
                    break;
                }
            }
            // else if (btns[i]==btns[OPTIONS]){

            // }
            else if (btns[i] == btns[QUIT])
            {
                SDL_Quit();
            }
        }
    }
}
PauseScreen::~PauseScreen() {}