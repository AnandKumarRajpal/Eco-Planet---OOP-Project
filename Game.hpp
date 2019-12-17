#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>

class Screens;
class MainScreen;
class StartScreen;
class GameOverScreen;
class PauseScreen;
class Instructions;
class IntroScreen;
class GameObject;
class RandomObj;
class Earth;
class Life;
class Enemies;
class Player;
class Powers;
//class Collision;

class Game
{
    SDL_Window *window = NULL;
    bool isPolluted, isRunning;
    int frameStart;
    int gap = 10000;

    MainScreen *mainscreen = NULL;
    StartScreen *startscreen = NULL;
    GameOverScreen *gameoverscreen = NULL;
    PauseScreen *pausescreen = NULL;
    IntroScreen *introscreen = NULL;
    Instructions *instructions1 = NULL;
    Instructions *instructions2 = NULL;
    Life **life = NULL;
    Earth *earth = NULL;
    GameObject **pollutedObj = NULL;
    GameObject **cleanObj = NULL;
    Screens *currentScreen = NULL;
    Enemies **enemy_list = NULL;
    Enemies *current_enemy = NULL;
    Player *player = NULL;
    GameObject **ecoFriendly = NULL;
    GameObject **nonecoFriendly = NULL;
    Powers *speedBoast = NULL;
    Powers *shield = NULL;
    RandomObj *inventory = NULL;
    //Collision * collision;
    GameObject *currentObj = NULL;

    SDL_Texture *starttex = NULL;
    SDL_Texture *maintex = NULL;
    SDL_Texture *gameovertex = NULL;
    SDL_Texture *introscreentex = NULL;
    SDL_Texture *instructions1tex = NULL;
    SDL_Texture *instructions2tex = NULL;
    SDL_Texture *buttontex = NULL;
    SDL_Texture *pausetex = NULL;
    SDL_Texture *deadTree = NULL;
    SDL_Texture *fire = NULL;
    SDL_Texture *smoke = NULL;
    SDL_Texture *cleantree = NULL;
    SDL_Texture *objectstex = NULL;
    SDL_Texture *deforesttex = NULL;
    SDL_Texture *intensivefarmingtex = NULL;
    SDL_Texture *fossilfueltex = NULL;
    SDL_Texture *playertex = NULL;

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
    static SDL_Renderer *renderer;
    bool check_collision(SDL_Rect, SDL_Rect);
};