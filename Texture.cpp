
#include "Texture.hpp"

SDL_Texture *Texture::loadTexture(std::string path)
{
    std::cout << "Load texture called" << std::endl;
    SDL_Surface *tmpsurface = IMG_Load(path.c_str());
    // printf("%p pointr tmp", tmpsurface);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tmpsurface);
    // printf("%p tx tmp", tex);
    SDL_FreeSurface(tmpsurface);
    return tex;
}