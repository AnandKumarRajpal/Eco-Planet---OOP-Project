#pragma once
#include "GameObject.hpp"
//#include "Location.hpp"
//#include "Weapon.hpp"
#include <iostream>

class Character : public GameObject
{
protected:
    int health;
    float speed;
    //Weapon* m_weapon;
    //Location* m_location;
    bool isDead;
    std::string m_direction;

public:
    Character(SDL_Texture *);
    void virtual Update() = 0;
    void virtual set_direction(std::string);
    void update_location();
    void die();
    virtual ~Character();
};