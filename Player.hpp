#pragma once
#include <iostream>
#include "GameObject.hpp"
#include "Inventory.hpp"

class Player : public GameObject
{
private:
    static Player *player;
     Player(SDL_Texture *);

public:
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Rect object_src;
    SDL_Rect object_dest;
    SDL_Rect *left;
    SDL_Rect *right;
    SDL_Rect *jump;
    SDL_Rect *attack;
    int walkframes;
    int jumpframes;
    int attackframes;
    int speed;
    std::string direction;
    int wkframe;
    int jkframe;
    int akframe;
    Inventory * inventory=NULL;
    static Player *instance(SDL_Texture*);
    virtual void Update() override;
    virtual void set_direction(std::string);
    ~Player();
    void HandleEvents(SDL_Event event);
    void update_dest();
};