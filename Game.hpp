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
class Texture;
class GameObject;
class Earth;
class Life;
class Enemies;
class Player;

class Game
{
    SDL_Window *window = NULL;
    bool isPolluted, isRunning;
    Uint32 frameStart;

    MainScreen *mainscreen = NULL;
    StartScreen *startscreen = NULL;
    GameOverScreen *gameoverscreen = NULL;
    PauseScreen *pausescreen = NULL;
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

    SDL_Texture *starttex = NULL;
    SDL_Texture *maintex = NULL;
    SDL_Texture *gameovertex = NULL;
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
    // int scrollingOffset = 0;

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
    bool check_collision(SDL_Rect, SDL_Rect);
    static SDL_Renderer *renderer;
};