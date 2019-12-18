#include "Enemies.hpp"
#include "Screens.hpp"
#include "GameObject.hpp"

Enemies::Enemies()
{
    std::cout << "Enemy Created";
}
Enemies::Enemies(SDL_Texture *tex, SDL_Texture *attack, GameObject *obj)
{
    objTexture = tex;
    attack_tex = attack;
    obj_required_to_kill = obj;
}
Enemies::~Enemies()
{
    delete obj_required_to_kill;
    std::cout << "Enemy Destroyed!" << std::endl;
}
void Enemies::Update() {}

// virtual void move();
// virtual bool check_death();