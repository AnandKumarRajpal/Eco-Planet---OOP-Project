
#include "IntroScreen.hpp"
IntroScreen::IntroScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    totalButtons = 1;
    btns = new Button *[1];
    btns[0] = new Button(1, 1, 20, 371, 620, 190);
    std::cout << "Start Screen constructor called" << std::endl;
}
void IntroScreen::Update() {}

IntroScreen::~IntroScreen()
{
}
