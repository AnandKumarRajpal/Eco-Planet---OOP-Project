#include "Game.hpp"
#include "Texture.hpp"
#include "Button.hpp"
#include "MainScreen.hpp"
#include "GameOverScreen.hpp"
#include "PauseScreen.hpp"
#include "StartScreen.hpp"
#include "GameObject.hpp"
#include "Life.hpp"
#include "Tree.hpp"
#include "Smoke.hpp"
#include "Fire.hpp"
#include "Earth.hpp"

SDL_Renderer *Game::renderer = nullptr;

bool Game::running()
{
    return isRunning;
}

Game::Game(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems initialised" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
}

void Game::init()
{
    //create objects
    startscreen = new StartScreen(starttex, buttontex);
    gameoverscreen = new GameOverScreen(gameovertex, buttontex);
    pausescreen = new PauseScreen(pausetex, buttontex);
    mainscreen = new MainScreen(maintex);
    life = new Life *[2];
    life[0] = new Life(objectstex, 10, 10, 550, 10, 0.5, 490, 100); //0.5
    life[1] = new Life(objectstex, 16, 117, 564, 24, 0.5, 437, 46); //change width according to life (changing 437 changed the width)
    earth = new Earth(objectstex, 580, 20, 800, 0, 1, 170, 170);
    pollutedObj = new GameObject *[3];
    pollutedObj[0] = new Tree(deadTree, 0, 0, 250, 350, 0.5, 91, 174); //0.5
    pollutedObj[1] = new Tree(deadTree, 90, 30, 600, 365, 1, 80, 145);
    //pollutedObj[3] = new Trash(objectstex, );
    //pollutedObj[3] = new Fire(fire, 0, 0, 350, 380, 0.2, 940, 280);    //0.2
    cleanObj = new GameObject *[1];
}

void Game::LoadMedia()
{
    buttontex = Texture::loadTexture("buttons.png");
    if (buttontex == NULL)
    {
        std::cout << "Button texture not loaded" << std::endl;
    }
    starttex = Texture::loadTexture("screens/Start Screen.png");
    if (starttex == NULL)
    {
        std::cout << "Start screen texture not loaded" << std::endl;
    }
    gameovertex = Texture::loadTexture("screens/Game Over.png");
    if (gameovertex == NULL)
    {
        std::cout << "Game over screen texture not loaded" << std::endl;
    }
    pausetex = Texture::loadTexture("screens/Pause Screen.png");
    if (pausetex == NULL)
    {
        std::cout << "Pause screen texture not loaded" << std::endl;
    }
    maintex = Texture::loadTexture("screens/Main Screen.png");
    if (maintex == NULL)
    {
        std::cout << "Main screen texture not loaded" << std::endl;
    }
    objectstex = Texture::loadTexture("sprites/objects.png");
    if (objectstex == NULL)
    {
        std::cout << "Objects Texture not loaded" << std::endl;
    }
    deadTree = Texture::loadTexture("sprites/dead tree.png");
    if (deadTree == NULL)
    {
        std::cout << "Dead tree texture not loaded" << std::endl;
    }
    smoke = Texture::loadTexture("sprites/smoke.png");
    if (smoke == NULL)
    {
        std::cout << "Smoke texture not loaded" << std::endl;
    }
    fire = Texture::loadTexture("sprites/fire.png");
    if (fire == NULL)
    {
        std::cout << "Fire texture not loaded" << std::endl;
    }
    cleantree = Texture::loadTexture("spirit/trees.pg");
    if (cleantree == NULL)
    {
        std::cout << "Trees texture not loaded" << std::endl;
    }
}

void Game::handleEvents()
{

    SDL_Event event;
    startscreen->handleEvents(&event);
}

void Game::Update()
{
    //button.Update();
}

void Game::Render()
{
    //clear screen
    SDL_RenderClear(renderer);
    //Render background
    if (currentScreen == mainscreen)
    {
        mainscreen->Update();
        for (int i = 0; i < 2; i++)
        {
            //pollutedObj[i]->Update();
            pollutedObj[i]->Render();
        }
        for (int i = 0; i < 2; i++)
        {

            life[i]->Render();
        }
        // cleanObj[0] = new Tree();
        // for (int i = 0; i < 3; i++)
        // {
        //     cleanObj[i]->Render();
        // }
        earth->Render();
    }
    else
    {
        currentScreen->Render();
    }
    //update screen
    SDL_RenderPresent(renderer);
}

void Game::gameLoop()
{
    currentScreen = mainscreen;
    while (isRunning)
    {
        Render();
        handleEvents();
        //break;
    }
}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

Game::~Game()
{
    delete mainscreen;
    delete startscreen;
    delete gameoverscreen;
    delete pausescreen;
}
