#include "StartScreen.hpp"

enum buttonNames
{
    STARTGAME = 0,
    //OPTIONS = 1,
    QUIT = 1,
    LOADGAME = 2,
};

StartScreen::StartScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    totalButtons = 3;
    btns = new Button *[4];
    btns[STARTGAME] = new Button(1, 1, 20, 371, 620, 190); //startgame button
    //btns[OPTIONS] = new Button(1, 191, 288, 375, 620, 190);   //options button
    btns[QUIT] = new Button(1251, 1, 555, 375, 620, 190);       //quit button
    btns[LOADGAME] = new Button(1250, 365, 288, 375, 620, 190); //load game button
    std::cout << "Start Screen constructor called" << std::endl;
}
void StartScreen::Update() {}

StartScreen::~StartScreen()
{
}