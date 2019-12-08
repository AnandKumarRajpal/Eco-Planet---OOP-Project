#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
//#include "MainScreen.hpp"
//#include "Texture.hpp"
//#include "Button.hpp"

class Screens;
class MainScreen;
class StartScreen;
class GameOverScreen;
class PauseScreen;
class Texture;
class Button;
class GameObject;
class Earth;
class Life;
class Smoke;
class Tree;
class Fire;

class Game
{
    SDL_Window *window = NULL;
    bool isRunning;

    MainScreen *mainscreen = NULL;
    StartScreen *startscreen = NULL;
    GameOverScreen *gameoverscreen = NULL;
    PauseScreen *pausescreen = NULL;
    Life **life = NULL;
    Earth *earth = NULL;
    GameObject **pollutedObj = NULL;
    GameObject **cleanObj = NULL;
    Screens *currentScreen = NULL;

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
    static SDL_Renderer *renderer;
};