#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Texture *tex, SDL_Texture *btn) : Screens(tex)
{
    totalButtons = 1;
    btns = new Button *[1];
    btns[0] = new Button(1050, 650, 0, 0, 161, 161);
    std::cout << "Main Screen constructor called" << std::endl;
}
void MainScreen::Update()
{
    if (scrollingOffset < -900)
    {
        scrollingOffset = 0;
    }
    this->Render(scrollingOffset, 0, 900, 500);
    this->Render(scrollingOffset + 900, 0, 900, 500);
    scrollingOffset--;
}
MainScreen::~MainScreen() {}
