#pragma once
#include <iostream>
#include "Character.hpp"

class Player : public Character
{
public:
    int walking_frames;
    int frame_jump;
    int weight;
    int state;
    int frame;
    SDL_Rect player_src;
    SDL_Rect player_dest;
    SDL_Rect *walking_left_arr;
    SDL_Rect *walking_right_arr;
    SDL_Rect *walking_jump_arr;

public:
    Player(SDL_Texture *);
    virtual void Update() override;
    virtual void set_direction(std::string) override;
    bool CollisionWithGround(float);
    ~Player();
    void setjump();
    void HandleEvents(SDL_Event event);
    void update_dest_rect();
};
