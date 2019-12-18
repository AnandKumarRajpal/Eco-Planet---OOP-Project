#include "Screens.hpp"
#include "Texture.hpp"
#include "Game.hpp"

Screens::Screens(SDL_Texture *tex, SDL_Texture *btntex)
{
    screenTexture = tex;
    btnTexture = btntex;
    std::cout << "Screens constructor called" << std::endl;
}

void Screens::Render()
{
    SDL_RenderCopy(Game::renderer, screenTexture, NULL, NULL);
    for (int i = 0; i < totalButtons; i++)
    {
        btns[i]->Render(btnTexture);
    }
    std::cout << "Screen rendered" << std::endl;
}
void Screens::Render(int x, int y, int width, int height)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, width, height};
    //Render to screen
    SDL_RenderCopyEx(Game::renderer, screenTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}
Screens::~Screens()
{
    for (int i = 0; i < totalButtons; i++)
    {
        delete[] btns[i];
    }
    delete[] btns;
}
void Screens::setColor(int r, int g, int b)
{
    SDL_SetTextureColorMod(this->screenTexture, r, g, b);
}