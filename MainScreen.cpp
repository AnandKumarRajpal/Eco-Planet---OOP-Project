#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    totalButtons = 1;
    btns = new Button *[1];
    btns[0] = new Button(1050, 660, 0, 0, 160, 160);
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
    scrollingOffset = scrollingOffset - 5;
    btns[0]->Render(btnTexture);
}

MainScreen::~MainScreen() {}
