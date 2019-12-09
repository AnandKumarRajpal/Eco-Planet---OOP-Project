#include "Enemies.hpp"
#include "Screens.hpp"
#include "GameObject.hpp"

Enemies::Enemies()
{
    std::cout << "Enemy Created";
}
Enemies::Enemies(SDL_Texture *tex, GameObject *obj)
{
    objTexture = tex;
    obj_required_to_kill = obj;
}
Enemies::~Enemies()
{
    std::cout << "Enemy Destroyed!" << std::endl;
}

void Enemies::Update()
{

}
// virtual void move();
// virtual bool check_death();