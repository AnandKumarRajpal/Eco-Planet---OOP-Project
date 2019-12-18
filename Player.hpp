#pragma once
#include <iostream>
#include "GameObject.hpp"
#include "Inventory.hpp"

class Player : public GameObject
{
private:
    static Player *player;
    Player(){};

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
    int state;
    std::string direction;
    int wkframe;
    int jkframe;
    int akframe;
    int groundYPos;
    float yVel = 0;
    float gravity = 2;
    bool jumping = false;
    Inventory * inventory=NULL;

public:
    Player(SDL_Texture *);
    static Player *instance();
    virtual void Update() override;
    virtual void set_direction(std::string);
    ~Player();
    bool CollisionWithGround(int);
    void HandleEvents(SDL_Event event);
    void update_dest();
    void check();
};