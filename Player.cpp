#include "Player.hpp"
Player *Player::player = NULL;
Player::Player(SDL_Texture *path) : GameObject(path)
{
    inventory= new Inventory();
    walkframes = 8;
    jumpframes = 7;
    attackframes = 3;
    attack = new SDL_Rect[attackframes];
    jump = new SDL_Rect[jumpframes];
    left = new SDL_Rect[walkframes];
    right = new SDL_Rect[walkframes];

    //player frames for animations
    for (int i = 0; i < walkframes; i++)
    {
        left[i].x = 0 + i * 64;
        left[i].y = 2250;
        left[i].w = 63;
        left[i].h = 60;

        right[i].x = 0 + i * 64;
        right[i].y = 2380;
        right[i].w = 63;
        right[i].h = 60;
    }
    for (int i = 0; i < jumpframes; i++)
    {

        jump[i].x = 0 + i * 64;
        jump[i].y = 1870;
        jump[i].w = 63;
        jump[i].h = 60;
    }
    for (int i = 0; i < attackframes; i++)
    {

        attack[i].x = 650 + i * 64;
        attack[i].y = 2890;
        attack[i].w = 52;
        attack[i].h = 60;
    }
    src = {0, 450, 75, 60};

    dest.w = src.w * 1.5;
    dest.h = src.h * 1.5;
    dest.x = xpos;
    dest.y = 368;

    this->srcRect = src;
    this->destRect = dest;
    direction = "walk_fixed";
    speed = 5;
}
//increasing the xpos or ypos depending upon the key pressed
void Player::Update()
{
    if (direction == "right" and xpos < 900)
    {
        xpos += speed;

        update_dest();
    }
    if (direction == "Jump" and xpos < 900)
    {
        update_dest();
    }
    else if (direction == "left" and xpos > 0)
    {
        xpos -= speed;
        update_dest();
    }
    else if (direction == "attack" and xpos < 900)
    {
        update_dest();
        }
    else
    {
        update_dest();
    }
}
//set the direction according to the key pressed
void Player::set_direction(std::string direct)
{
    direction = direct;
}
//singleton class implemented here
// a pointer to this class will be used in all other classes.
Player *Player::instance(SDL_Texture *path)
{
    if (!player)
        player = new Player(path);
    return player;
}
//updates the xpos and ypos of the player according to the key pressed
void Player::update_dest()
{
    wkframe++;
    jkframe++;
    akframe++;
    if (wkframe / 8 >= walkframes)
    {
        wkframe = 0;
    }
    if (jkframe / 7 >= jumpframes)
    {
        jkframe = 0;
    }
    if (akframe / 3 >= attackframes)
    {
        akframe = 0;
    }
    if (direction == "Jump")
    {
        srcRect = jump[jkframe / 7];
        //destRect.y = 330;
        destRect.y = destRect.y - 10;
    }
    else if (direction == "left")
    {
        srcRect = left[wkframe / 8];
        object_dest.x = xpos;
        destRect.x = xpos;
    }
    else if (direction == "right")
    {
        srcRect = right[wkframe / 8];
        object_dest.x = xpos;
        destRect.x = xpos;
    }
    else if (direction == "attack")
    {
        srcRect = attack[akframe / 3];
    }
    else if (direction == "original")
    {
        srcRect = right[wkframe / 8];
        destRect.y = 368;
    }
    else
    {
        if (direction == "Jump")
        {
            destRect.x = xpos;
        }
        else
        {
            srcRect = right[wkframe / 8];
            destRect.x = xpos;
        }
    }
}
//destructor 
Player::~Player()
{

    delete right;
    delete left;
    delete jump;
    delete inventory;
}
