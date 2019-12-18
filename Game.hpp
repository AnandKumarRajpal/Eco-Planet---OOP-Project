#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include "Collision.hpp"
#include "ScreenFactory.hpp"

class Screens;
class GameObject;
class RandomObj;
class Earth;
class Life;
class Enemies;
class Player;
class Powers;

class Game
{
    SDL_Window *window = NULL;
    bool isPolluted, isRunning, enemyAlive=true;
    int frameStart, enemiesKilled;

    ScreenFactory factory;
    Screens *mainscreen = NULL;
    Screens *startscreen = NULL;
    Screens *gameoverscreen = NULL;
    Screens *pausescreen = NULL;
    Screens *introscreen = NULL;
    Screens *instructions1 = NULL;
    Screens *instructions2 = NULL;
    Life **life = NULL;
    Earth *earth = NULL;
    GameObject **pollutedObj = NULL;
    GameObject **cleanObj = NULL;
    Screens *currentScreen = NULL;
    Enemies **enemy_list = NULL;
    Enemies *current_enemy = NULL;
    GameObject **ecoFriendly = NULL;
    GameObject **nonecoFriendly = NULL;
    Powers *speedBoast = NULL;
    Powers *shield = NULL;
    RandomObj *inventory = NULL;
    Collision collision = Collision();
    GameObject *currentObj = NULL;
    GameObject* currentobjs[5];

    SDL_Texture *starttex = NULL;
    SDL_Texture *maintex = NULL;
    SDL_Texture *gameovertex = NULL;
    SDL_Texture *introscreentex = NULL;
    SDL_Texture *instructions1tex = NULL;
    SDL_Texture *instructions2tex = NULL;
    SDL_Texture *buttontex = NULL;
    SDL_Texture *pausetex = NULL;
    SDL_Texture *deadTree = NULL;
    SDL_Texture *smoke = NULL;
    SDL_Texture *cleantree = NULL;
    SDL_Texture *objectstex = NULL;
    SDL_Texture *deforesttex = NULL;
    SDL_Texture *intensivefarmingtex = NULL;
    SDL_Texture *fossilfueltex = NULL;
    SDL_Texture *playertex = NULL;
    SDL_Texture * attack_tex =NULL;
    Player *player=NULL;
    bool object = false;
    int f=0, g=0;
public:
    Game(const char *, int, int, int, int, bool);
    ~Game();
    void init();
    void handleEvents();
    void LoadMedia();
    void Update();
    void Render();
    void Clean();
    void gameLoop();
    bool running();
    void loadGame();
    void saveGame();
    void reset();
    static SDL_Renderer *renderer;
};