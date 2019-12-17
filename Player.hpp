#pragma once
#include <iostream>
#include "GameObject.hpp"

class Player : public GameObject
{
public:
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Rect *left;
    SDL_Rect *right;
    SDL_Rect *jump;
    int walkframes;
    int frame_jump;
    int speed;
    int state;
    std::string direction;
    int frame;

public:
    Player(SDL_Texture *);
    virtual void Update() override;
    virtual void set_direction(std::string);
    bool CollisionWithGround(float);
    ~Player();
    void setjump();
    void HandleEvents(SDL_Event event);
    void update_dest();
};

// class Singleton 
// { 
//     private static Singleton obj; 
  
//     // private constructor to force use of 
//     // getInstance() to create Singleton object 
//     private Singleton() {} 
  
//     public static Singleton getInstance() 
//     { 
//         if (obj==null) 
//             obj = new Singleton(); 
//         return obj; 
//     } 
// } 