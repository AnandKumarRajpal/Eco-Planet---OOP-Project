#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    //renders buttons on screens
    totalButtons = 1;
    btns = new Button *[1];
    btns[0] = new Button(1438, 822, 0, 0, 162, 161); //1600 984
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
MainScreen::~MainScreen() 
{}
