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
    //renders buttons on screens
    totalButtons = 4;
    btns = new Button *[3];
    btns[OPTIONS] = new Button(10, 188, 300, 80, 620, 190);
    btns[RESUME] = new Button(10, 368, 300, 180, 620, 190);
    btns[QUIT] = new Button(1251, 1, 300, 280, 620, 190);
    btns[SOUND] = new Button(10, 736, 300, 370, 620, 190);
    std::cout << "Pause Screen constructor called" << std::endl;
}
void PauseScreen::Update() {}

PauseScreen::~PauseScreen() {}