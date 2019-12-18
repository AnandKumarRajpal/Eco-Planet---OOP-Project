#include "GameOverScreen.hpp"

enum buttonNames
{
    QUIT = 0,
    PLAYAGAIN = 1,
};
GameOverScreen::GameOverScreen(SDL_Texture *tex, SDL_Texture *buttontex) : Screens(tex, buttontex)
{
    //renders buttons on screens
    totalButtons = 2;
    btns = new Button *[2];
    btns[QUIT] = new Button(1250, 7, 500, 380, 620, 190);
    btns[PLAYAGAIN] = new Button(1251, 195, 200, 380, 620, 190);
    std::cout << "Game Over Screen constructor called" << std::endl;
}
void GameOverScreen::Update() {}
GameOverScreen::~GameOverScreen(){

}