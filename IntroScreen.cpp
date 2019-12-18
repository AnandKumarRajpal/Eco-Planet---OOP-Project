
#include "IntroScreen.hpp"

IntroScreen::IntroScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    //renders buttons on screens
    totalButtons = 1;
    btns = new Button *[1];
    btns[0] = new Button(1254, 555, 650, 400, 620, 190);
    std::cout << "Start Screen constructor called" << std::endl;
}
void IntroScreen::Update() {}

IntroScreen::~IntroScreen()
{
}
