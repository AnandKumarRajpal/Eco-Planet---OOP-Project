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
#include "Enemies.hpp"
#include "Deforestation.hpp"
#include "IntensiveFarming.hpp"
#include "FosilFuels.hpp"

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
    //rec = {564, 24, 437, 46};
    earth = new Earth(objectstex, 580, 20, 800, 0, 0.5, 170, 170);
    pollutedObj = new GameObject *[3];
    pollutedObj[0] = new Tree(deadTree, 0, 0, 250, 350, 0.5, 91, 174); //0.5
    pollutedObj[1] = new Tree(deadTree, 90, 30, 600, 365, 0.5, 80, 145);
    //pollutedObj[3] = new Trash(objectstex, );
    //pollutedObj[3] = new Fire(fire, 0, 0, 350, 380, 0.2, 940, 280);    //0.2
    cleanObj = new GameObject *[6];
    cleanObj[0] = new Tree(cleantree, 0, 83, 250, 390, 1, 110, 61);
    cleanObj[1] = new Tree(cleantree, 157, 127, 450, 390, 1, 35, 50);
    cleanObj[2] = new Tree(cleantree, 130, 280, 560, 380, 1, 60, 70);
    cleanObj[3] = new Tree(cleantree, 317, 426, 100, 408, 1, 20, 38);
    cleanObj[4] = new Tree(cleantree, 317, 426, 125, 408, 1, 20, 38);
    cleanObj[5] = new Tree(cleantree, 317, 426, 780, 410, 1, 20, 38);
    enemy_list = new Enemies *[3];
    enemy_list[0] = new Deforestation(deforesttex, NULL);
    enemy_list[1] = new IntensiveFarming(intensivefarmingtex, NULL);
    enemy_list[2] = new FossilFuel(fossilfueltex, NULL);
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
    cleantree = Texture::loadTexture("sprites/trees.png");
    if (cleantree == NULL)
    {
        std::cout << "Trees texture not loaded" << std::endl;
    }
    deforesttex = Texture::loadTexture("sprites/enemy1.png");
    if (deforesttex == NULL)
    {
        std::cout << "Deforestation texture not loaded" << std::endl;
    }
    intensivefarmingtex = Texture::loadTexture("sprites/enemy2.png");
    if (intensivefarmingtex == NULL)
    {
        std::cout << "Intensive Farming texture not loaded" << std::endl;
    }
    fossilfueltex = Texture::loadTexture("sprites/enemy3.png");
    if (fossilfueltex == NULL)
    {
        std::cout << "Fossil fuels texture not loaded" << std::endl;
    }
}

void Game::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
        {
            // Get mouse position
            int x, y;
            SDL_GetMouseState(&x, &y);
            for (int i = 0; i < currentScreen->totalButtons; i++)
            {
                if (currentScreen->btns[i]->isOverMouse(x, y))
                {
                    if (currentScreen == startscreen)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //startgame
                            {
                                currentScreen = mainscreen;
                            }
                            else if (i == 1)
                            {
                                currentScreen = startscreen;
                            }
                            else if (i == 2) //quit
                            {
                                isRunning = false;
                            }
                        }
                    }
                    else if (currentScreen == pausescreen)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //options
                            {
                            }
                            else if (i == 1) //resume
                            {
                                //currentScreen = mainscreen;
                            }
                            else if (i == 2) //quit
                            {
                                isRunning = false;
                            }
                            else if (i == 3) //sound
                            {
                            }
                        }
                    }
                    else if (currentScreen == gameoverscreen)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //quit
                            {
                                isRunning = false;
                            }
                            else if (i == 1) //playagain
                            {
                                currentScreen = mainscreen;
                            }
                        }
                    }
                }
            }
        }
    }
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
        enemy_list[0]->Render(); //abhi bhi thora ajeeeb sa hora hai /kya hua?
        if (isPolluted)
        {
            for (int i = 0; i < 2; i++)
            {
                //pollutedObj[i]->Update();
                pollutedObj[i]->Render();
            }
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                cleanObj[i]->Render();
            }
        }
        for (int i = 0; i < 2; i++)
        {
            life[i]->Render();
        }
        earth->Render();
    }
    else
    {
        currentScreen->Render();
        enemy_list[0]->Render();
    }
    //update screen
    SDL_RenderPresent(renderer);
}

void Game::gameLoop()
{
    currentScreen = startscreen;
    isPolluted = true;
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
    delete earth;

    for (int i = 0; i < 2; i++)
    {
        delete[] life[i];
    }
    for (int i = 0; i < 3; i++)
    {
        delete[] pollutedObj[3];
    }
    for (int i = 0; i < 6; i++)
    {
        delete[] cleanObj[i];
    }
    delete[] life;
    delete[] pollutedObj;
    delete[] cleanObj;
}
