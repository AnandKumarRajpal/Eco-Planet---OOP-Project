#pragma once
#include <SDL.h>
#include "GameObject.hpp"

class Enemies : public GameObject
{

    public:
        GameObject *obj_required_to_kill;
        SDL_Rect destRect = {600, 348, 136, 114};
        SDL_Texture *attack_tex;
        SDL_Rect srcrect_attack;
        SDL_Rect dstrect_attack = {600, 390, 50, 50 };
        bool attack = false;
        Enemies();
        Enemies(SDL_Texture *, SDL_Texture *, GameObject *);
        virtual ~Enemies();
        void Update();
        virtual void Render() = 0;
        virtual void Render(int) = 0;
        virtual void Hatchet() = 0;
        // virtual void move();
        // virtual bool check_death();
};