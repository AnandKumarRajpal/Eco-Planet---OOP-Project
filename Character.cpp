#include "Character.hpp"

Character::Character(SDL_Texture *filepath)
    : GameObject(filepath)
{
    // this->src_rec.x = img_rect->x;
    // this->src_rec.y = img_rect->y;
    // this->src_rec.h = img_rect->h;
    // this->src_rec.y = img_rect->y;

    //m_weapon = nullptr;
    //m_location = nullptr;
}

void Character::set_direction(std::string a) {}
void Character::update_location() {}
void Character::die() {}
Character::~Character() {}
