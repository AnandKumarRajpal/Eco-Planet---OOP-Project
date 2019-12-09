#pragma once
#include <iostream>
#include "Character.hpp"

class Player : public Character
{
public:
    int walking_frames;
    int weight;
    int state;
    int frame;
    float myGravity = 0.2f;
    float maxFallSpeed = -5.0f;
    float myJumpForce = 5.0f;
    float curJumpForce = 0.0f;
    bool m_jumping = false;
    float deltaTime;
    static int obj_count;
    SDL_Rect player_src;
    SDL_Rect player_dest;
    SDL_Rect *walking_left_arr;
    SDL_Rect *walking_right_arr;
    SDL_Rect *walking_jump_arr;

public:
    Player(SDL_Texture *);
    virtual void Update() override;
    virtual void set_direction(std::string) override;
    int yVel, gravity;
    bool jumping = false;
    bool CollisionWithGround();
    ~Player();
    void HandleEvents(SDL_Event event);
    void update_dest_rect();
};
