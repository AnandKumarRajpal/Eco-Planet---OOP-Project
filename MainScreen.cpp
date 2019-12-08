#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Texture *tex) : Screens(tex)
{
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
void MainScreen::handleEvents(SDL_Event *e)
{
}
MainScreen::~MainScreen() {}
