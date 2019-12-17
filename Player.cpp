#include "Player.hpp"

Player::Player(SDL_Texture *path) : GameObject(path)
{
    path = path;
    walkframes = 8;
    jump = new SDL_Rect[walkframes];
    left = new SDL_Rect[walkframes];
    right = new SDL_Rect[walkframes];

    //player frames
    for (int i = 0; i < walkframes; i++)
    {
        left[i].x = 0 + i * 64;
        left[i].y = 580;
        left[i].w = 63;
        left[i].h = 60;

        jump[i].x =5  + i * 64;
        jump[i].y = 200;
        jump[i].w = 63;
        jump[i].h = 60;

        right[i].x = 0 + i * 64;
        right[i].y = 710;
        right[i].w = 63;
        right[i].h = 60;
    }
    src = {0, 450, 75, 60};
      
    dest.w = src.w* 1.5;
    dest.h = src.h* 1.5;
    dest.x = xpos;
    dest.y = 365; //385


    this->srcRect = src;
    this->destRect = dest;
    direction="static";
    speed = 3.5;
}

void Player::Update()
{
    if (direction == "right" and xpos < 900)
    {
        xpos += speed;
        update_dest();
    }
    // if (m_direction == "Jump" and xpos < 900)
    // {
    //     ypos=330;
    //     update_dest_rect();
    // }
    else if (direction == "left" and xpos > 0)
    {
        xpos -= speed;
        update_dest();
    }
    else
    {
        update_dest();
    }
}

void Player::set_direction(std::string direct)
{
    direction =direct;
}

void Player::update_dest()
{
    frame++;
    if (frame / 8 >= walkframes)
    {
        frame = 0;
    }
    if (direction == "Jump")
    {
        srcRect = jump[frame / 8];
        destRect.y = 200;
    }
    if (direction == "left")
    {
        srcRect = left[frame / 8];
        destRect.x = xpos;
    }
    else if (direction == "right")
    {
        srcRect = right[frame / 8];
        destRect.x = xpos;
    }
    else if(direction=="original"){
        srcRect = jump[frame / 8];
        destRect.y = 385;
    }
    else
    {
        // srcRect = right[frame / 8];
        // destRect.x = xpos;
    }
}

Player::~Player()
{
    delete right;
    delete left;
    delete jump;
}

