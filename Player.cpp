#include "Player.hpp"

Player::Player(SDL_Texture *file) : Character(file)
{
    // x1.x = 250;
    // x1.y = 130;
    // x1.h = 70;
    // x1.w = 60;
    walking_frames = 8;
    walking_left_arr = new SDL_Rect[walking_frames];
    walking_right_arr = new SDL_Rect[walking_frames];
    walking_jump_arr = new SDL_Rect[walking_frames];

    //set player frames
    for (int i = 0; i < walking_frames; i++)
    {
        walking_jump_arr[i].x = 0 + i * 64;
        walking_jump_arr[i].y = 580;
        walking_jump_arr[i].w = 63;
        walking_jump_arr[i].h = 60;

        walking_left_arr[i].x = 0 + i * 64;
        walking_left_arr[i].y = 580;
        walking_left_arr[i].w = 63;
        walking_left_arr[i].h = 60;

        walking_right_arr[i].x = 0 + i * 64;
        walking_right_arr[i].y = 710;
        walking_right_arr[i].w = 63;
        walking_right_arr[i].h = 60;
    }

    player_src = {0, 450, 75, 60};

    player_dest.w = player_src.w;
    player_dest.h = player_src.h;
    player_dest.x = xpos;
    player_dest.y = 450;

    this->srcRect = player_src;
    this->destRect = player_dest;
    m_direction = "static";
    speed = 3.5;
}

bool Player::CollisionWithGround()
{
    if (yVel > 0)
    {
        return true;
    }

    return false;
}

void Player::Update()
{

    if (m_direction == "right" and xpos < 730)
    {
        xpos += speed;
        update_dest_rect();
    }
    if (m_direction == "jump" and xpos < 0)
    {
        destRect.y = 440;
        update_dest_rect();
    }

    else if (m_direction == "left" and xpos > 0)
    {
        xpos -= speed;
        update_dest_rect();
    }
    else
    {
        update_dest_rect();
    }
}

void Player::set_direction(std::string dir)
{
    m_direction = dir;
}

void Player::update_dest_rect()
{
    frame++;
    if (frame / 8 >= walking_frames)
    {
        frame = 0;
    }
    if (m_direction == "jump")
    {
        srcRect = walking_jump_arr[frame / 8];
    }
    if (m_direction == "left")
    {
        srcRect = walking_left_arr[frame / 8];
        destRect.x = xpos;
    }
    else if (m_direction == "right")
    {
        srcRect = walking_right_arr[frame / 8];
        destRect.x = xpos;
    }
    else
    {
        srcRect = player_src;
        destRect.x = xpos;
        //destRect.y = ypos;
    }
}

Player::~Player()
{
    //deletion of all objects further
    delete walking_right_arr;
    delete walking_left_arr;
}