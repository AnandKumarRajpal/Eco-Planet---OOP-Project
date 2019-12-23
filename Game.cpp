#include "Game.hpp"
#include "Texture.hpp"
#include "GameObject.hpp"
#include "Life.hpp"
#include "Tree.hpp"
#include "Smoke.hpp"
#include "Earth.hpp"
#include "Enemies.hpp"
#include "Deforestation.hpp"
#include "IntensiveFarming.hpp"
#include "FosilFuels.hpp"
#include "Player.hpp"
#include "RandomObj.hpp"
#include "Powers.hpp"
#include "Collision.hpp"
#include <iostream>
#include <fstream>
#include <time.h>

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
    //creating all game screens
    //factory design pattern implementedk, takes textures to be used for the screen
    startscreen = factory.CreateScreen("startscreen", starttex, buttontex);
    gameoverscreen = factory.CreateScreen("gameoverscreen", gameovertex, buttontex);
    pausescreen = factory.CreateScreen("pausescreen", pausetex, buttontex);
    mainscreen = factory.CreateScreen("mainscreen", maintex, playertex);
    introscreen = factory.CreateScreen("introscreen", introscreentex, buttontex);
    instructions1 = factory.CreateScreen("instructionsscreen", instructions1tex, buttontex);
    instructions2 = factory.CreateScreen("instructionsscreen", instructions2tex, buttontex);
    //creating life object
    life = new Life *[2];
    life[0] = new Life(objectstex, 10, 10, 550, 10, 0.5, 490, 103);
    life[1] = new Life(objectstex, 16, 117, 564, 23, 0.5, 437, 46);
    //creating earth object
    earth = new Earth(objectstex, 580, 20, 800, 0, 0.4, 170, 170);
    //creating list of polluted objects
    pollutedObj = new GameObject *[6];
    //appending to list of polluted Objects
    pollutedObj[0] = new Tree(deadTree, 0, 0, 250, 310, 0.8, 91, 174);
    pollutedObj[1] = new Tree(deadTree, 90, 30, 500, 335, 0.8, 80, 145);
    pollutedObj[2] = new Tree(deadTree, 0, 0, 750, 310, 0.8, 91, 174);
    pollutedObj[3] = new Smoke(smoke, 20, 30, 250, 25, 0.5, 200, 193);
    pollutedObj[4] = new Smoke(smoke, 290, 290, 450, 90, 0.5, 180, 190);
    pollutedObj[5] = new Smoke(smoke, 800, 1060, 750, 50, 0.5, 190, 191);
    //creating list to store clean objects
    cleanObj = new GameObject *[6];
    //appending to list of clean Object
    cleanObj[0] = new Tree(cleantree, 0, 83, 250, 390, 1, 110, 61);
    cleanObj[1] = new Tree(cleantree, 157, 127, 450, 390, 1, 35, 50);
    cleanObj[2] = new Tree(cleantree, 130, 280, 560, 380, 1, 60, 70);
    cleanObj[3] = new Tree(cleantree, 317, 426, 100, 408, 1, 20, 38);
    cleanObj[4] = new Tree(cleantree, 317, 426, 125, 408, 1, 20, 38);
    cleanObj[5] = new Tree(cleantree, 317, 426, 780, 410, 1, 20, 38);
    //creating enemies list
    enemy_list = new Enemies *[3];
    //appending three game enemies to list
    enemy_list[0] = new Deforestation(deforesttex,attack_tex, NULL);
   /*  enemy_list[1] = new IntensiveFarming(intensivefarmingtex, NULL);
    enemy_list[2] = new FossilFuel(fossilfueltex, NULL); */
    player = Player::instance(playertex);
    //creating list of objects to be collected by player
    ecoFriendly = new GameObject *[9];
    //creating list of objects not to be collected by player
    nonecoFriendly = new GameObject *[8];
    ecoFriendly[0] = new RandomObj(objectstex, 30, 238, 800, 395, 0.2, 240, 243);
    ecoFriendly[1] = new RandomObj(objectstex, 305, 238, 800, 300, 0.2, 240, 243);
    ecoFriendly[2] = new RandomObj(objectstex, 588, 238, 800, 250, 0.2, 240, 243);
    ecoFriendly[3] = new RandomObj(objectstex, 868, 234, 800, 395, 0.2, 240, 243);
    ecoFriendly[4] = new RandomObj(objectstex, 1149, 234, 800, 380, 0.2, 240, 243);
    ecoFriendly[5] = new RandomObj(objectstex, 26, 518, 800, 395, 0.2, 240, 243);
    ecoFriendly[6] = new RandomObj(objectstex, 1160, 518, 800, 250, 0.2, 240, 243);
    ecoFriendly[7] = new RandomObj(objectstex, 1440, 518, 800, 200, 0.2, 240, 243);
    ecoFriendly[8] = new RandomObj(objectstex, 21, 798, 800, 280, 0.2, 240, 243);
    nonecoFriendly[0] = new RandomObj(objectstex, 1428, 238, 800, 325, 0.2, 240, 243);
    nonecoFriendly[1] = new RandomObj(objectstex, 1710, 234, 800, 300, 0.2, 240, 243);
    nonecoFriendly[2] = new RandomObj(objectstex, 1720, 517, 800, 395, 0.2, 240, 243);
    nonecoFriendly[3] = new RandomObj(objectstex, 300, 516, 800, 150, 0.2, 240, 243);
    nonecoFriendly[4] = new RandomObj(objectstex, 580, 517, 800, 200, 0.2, 240, 243);
    nonecoFriendly[5] = new RandomObj(objectstex, 865, 517, 800, 250, 0.2, 240, 243);
    nonecoFriendly[6] = new RandomObj(objectstex, 300, 797, 800, 280, 0.2, 240, 243);
    nonecoFriendly[7] = new RandomObj(objectstex, 580, 797, 800, 395, 0.2, 240, 243);
    //appending to list of Powers 
    speedBoast = new Powers(objectstex, 856, 800, 800, 290, 0.2, 244, 244);
    shield = new Powers(objectstex, 1155, 798, 800, 300, 0.2, 238, 246);
}

void Game::LoadMedia() //loads all textures needed for game
{
    playertex = Texture::loadTexture("sprites/playerss.png");
    if (playertex == NULL)
    {
        std::cout << "Player texture not loaded" << std::endl;
    }
    buttontex = Texture::loadTexture("sprites/buttons.png");
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
    objectstex = Texture::loadTexture("sprites/playerss.png");
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
    introscreentex = Texture::loadTexture("screens/Intro Screen.jpg");
    if (introscreentex == NULL)
    {
        std::cout << "Intro screen texture not loaded" << std::endl;
    }
    instructions1tex = Texture::loadTexture("screens/Instructions.png");
    if (instructions1tex == NULL)
    {
        std::cout << "Instructions Screen 1 texture not loaded" << std::endl;
    }
    instructions2tex = Texture::loadTexture("screens/Instructions 2.png");
    if (instructions2tex == NULL)
    {
        std::cout << "Instructions Screen 2 texture not loaded" << std::endl;
    }
    attack_tex = Texture::loadTexture("sprites/ss.png");
    if(attack_tex == NULL)
    {
        std::cout << "Attack texture not loaded" << std::endl;
    }

}

void Game::saveGame() //saves game in txt file after enemy is killed
{
    std::ofstream file;
    file.open("savegame.txt");
    file << life[1]->lifeValue << "\n";
    file << player->destRect.x << "\n";
    file << player->destRect.y << "\n";
    if (isPolluted)
    {
        file << "true"
             << "\n";
        file << pollutedObj[0]->GetX() << "\n";
        file << pollutedObj[1]->GetX() << "\n";
        file << pollutedObj[2]->GetX() << "\n";
        file << pollutedObj[3]->GetX() << "\n";
        file << pollutedObj[4]->GetX() << "\n";
        file << pollutedObj[5]->GetX() << "\n";
    }
    else
    {
        file << "false"
             << "\n";
        file << cleanObj[0]->GetX() << "\n";
        file << cleanObj[1]->GetX() << "\n";
        file << cleanObj[2]->GetX() << "\n";
        file << cleanObj[3]->GetX() << "\n";
        file << cleanObj[4]->GetX() << "\n";
        file << cleanObj[5]->GetX() << "\n";
    }
    file << enemiesKilled << "\n";
    //current enemy

    file.close();
}

void Game::loadGame() //loads game from txt file to start a previously loaded game
{
    std::ifstream file("savegame.txt");
    std::string line;
    if (file.is_open())
    {
        getline(file, line);
        life[1]->destRect.w = atoi(line.c_str());
        player->destRect.x = atoi(line.c_str());
        player->destRect.y = atoi(line.c_str());
        if (line.c_str() == "true")
        {
            isPolluted = true;
             pollutedObj[0]->destRect.x = atoi(line.c_str());
            pollutedObj[1]->destRect.x = (atoi(line.c_str()));
            pollutedObj[2]->destRect.x = (atoi(line.c_str()));
            pollutedObj[3]->destRect.x = (atoi(line.c_str()));
            pollutedObj[4]->destRect.x = (atoi(line.c_str()));
            pollutedObj[5]->destRect.x = (atoi(line.c_str()));
        }
        else if (line.c_str() == "false")
        {
            isPolluted = false;
              cleanObj[0]->destRect.x = (atoi(line.c_str()));
            cleanObj[1]->destRect.x = (atoi(line.c_str()));
            cleanObj[2]->destRect.x = (atoi(line.c_str()));
            cleanObj[3]->destRect.x = (atoi(line.c_str()));
            cleanObj[4]->destRect.x = (atoi(line.c_str()));
            cleanObj[5]->destRect.x = (atoi(line.c_str()));
        }
        enemiesKilled = atoi(line.c_str());
        file.close();
    }
    currentScreen = mainscreen;
}
void Game::reset()
{
    life[1]->destRect.w =218;
    isPolluted=true;
    enemiesKilled=0;
}
void Game::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
       switch (e.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        // player movement depending upon the keys pressed
        case SDL_KEYDOWN:

            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                
                player->set_direction("Jump");
                
                
                break;
            case SDLK_LEFT:
                player->set_direction("left");
                break;
            case SDLK_RIGHT:
                player->set_direction("right");
                break;
            case SDLK_SPACE:
            //initializing the objects destRect according to players position
                ecoFriendly[0]->destRect.x = player->destRect.x + 73;
                ecoFriendly[0]->destRect.y = player->destRect.y + 25;
                ecoFriendly[0]->destRect.w = player->destRect.w * 0.3;
                ecoFriendly[0]->destRect.h = player->destRect.h * 0.3;
                object = true;
                player->set_direction("attack");
                break;
            default:
                player->set_direction("walk_fixed");
                break;
            }
            break;
        case SDL_KEYUP:
            if (e.key.keysym.sym == SDLK_UP)
            {
                player->set_direction("original");
                break;
            }
            else
            {
                player->set_direction("walk_fixed");
                break;
            }
            break;
        }
        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
        {
            // Get mouse position
            int x, y;
            SDL_GetMouseState(&x, &y);
            for (int i = 0; i < currentScreen->totalButtons; i++)
            {
                if (currentScreen->btns[i]->isOverMouse(x, y))
                {
                    if (currentScreen == introscreen)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //next
                            {
                                currentScreen = instructions1;
                            }
                        }
                    }
                    else if (currentScreen == instructions1)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //next
                            {
                                currentScreen = instructions2;
                            }
                        }
                    }
                    else if (currentScreen == instructions2)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //next
                            {
                                currentScreen = mainscreen;
                            }
                        }
                    }
                    else if (currentScreen == startscreen)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //startgame
                            {
                                currentScreen = introscreen;
                            }
                            else if (i == 1) //loadgame
                            {
                                isPolluted=false;
                                loadGame();
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
                                reset();
                                currentScreen = mainscreen;
                            }
                        }
                    }
                    else if (currentScreen == mainscreen)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (i == 0) //pause
                            {
                                currentScreen = pausescreen;
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
    player->Update();
}
void Game::Render()
{
    srand(time(0));
    SDL_RenderClear(renderer);
    if (currentScreen == mainscreen)
    {
        //gets current time of game since start
        Uint32 ticks=SDL_GetTicks();
        mainscreen->Update();
        if (isPolluted)
        {
            //renders polluted background
            for (int i = 0; i < 6; i++)
            {
                pollutedObj[i]->Update();
            }
            mainscreen->setColor(150, 75, 0);
        }
        else
        {
            //renders clean background
            for (int i = 0; i < 6; i++)
            {
                cleanObj[i]->Update();
            }
            mainscreen->setColor(85, 85, 85);
        }
        earth->Render();
        player->Render();
        life[0]->Render();
        //updates earths life
        life[1]->Update();
        //game end condition
        if (life[1]->destRect.w <= 0)
        {
            currentScreen = gameoverscreen;
        }
        //randomly generates objects to collect throughout game
        if(ticks%200 == 0 && f < 9)
        {
            currentobjs[f] = ecoFriendly[rand()%8];
            std::cout << "added new" << std::endl;
            f++;
        }
        for(int i=0; i < f; i++)
        {
            if ((collision.check_collision(player->destRect, currentobjs[i]->destRect)) == false){
                currentobjs[i]->UpdateObj();
                std::cout << "rendered stored" << std::endl;
            }
            else
            {
                player->inventory->append(currentobjs[i]);
                currentobjs[i]->destRect.x=10000;
            }
        }
        if(ticks%500 == 0 && g < 10)
        {
            currentobjs[g] = nonecoFriendly[rand()%9];
            std::cout << "added new" << std::endl;
            g++;
        }
        //detecs collision between player and objects and stores it to inventory of player
        for(int i=0; i < g; i++)
        {
            if ((collision.check_collision(player->destRect, currentobjs[i]->destRect)) == false){
                currentobjs[i]->UpdateObj();
                std::cout << "rendered stored" << std::endl;
            }
            else
            {
                life[1]->destRect.w = life[1]->destRect.w - 50; 
                currentobjs[i]->destRect.x=10000;
            }
        }
        //if list size gets greater than total objects, it restores
        if(f > 8)
        {
            f = 0;
        }
        if(g > 9){
            g = 0;
        }
        //if attack key is pressed then render the object on the screen
        if (object == true)
        {
            if ((collision.check_collision(enemy_list[0]->destRect, ecoFriendly[0]->destRect)) == false){
                ecoFriendly[0]->Update();
            }
            else
            {
                enemiesKilled=1;
                enemyAlive=false;
                isPolluted = false;
                saveGame();
                
            }
        }
        //enemy attacks
        if (ticks % 5000 && enemyAlive==true && enemiesKilled <1)
        {
            if(enemy_list[0]->attack == false)
            {
                enemy_list[0]->Render(285);
                enemy_list[0]->attack = true;
            }
            else if(enemy_list[0]->attack)
            {
                enemy_list[0]->Render();
                enemy_list[0]->Hatchet();
            }
            else
            {
                enemy_list[0]->Render();
            }
        }
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
    const int FPS = 60;
    const int framedelay = 1000 / FPS;
    int frameTime;
    currentScreen = startscreen;
    isPolluted = true;
    while (isRunning)
    {
        handleEvents();
        Update();
        Render();
        //break;
        frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks() - frameStart;

        if (framedelay > frameTime)
        {
            SDL_Delay(framedelay - frameTime);
        }
    }
    //saveGame();
    Clean();
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
    delete introscreen;
    delete instructions1;
    delete instructions2;

    for (int i = 0; i < 2; i++)
    {
        delete[] life[i];
    }
    for (int i = 0; i < 6; i++)
    {
        delete[] pollutedObj[3];
    }
    for (int i = 0; i < 6; i++)
    {
        delete[] cleanObj[i];
    }
    for (int i = 0; i < 3; i++)
    {
        delete[] enemy_list[i];
    }
    for (int i = 0; i < 9; i++)
    {
        delete[] ecoFriendly[i];
    }
    for (int i = 0; i < 8; i++)
    {
        delete[] nonecoFriendly[i];
    }
    delete[] life;
    delete[] pollutedObj;
    delete[] cleanObj;
    delete[] enemy_list;
    delete speedBoast;
    delete shield;
    delete inventory;
    std::cout << "Memory deallocated" << std::endl;
}
