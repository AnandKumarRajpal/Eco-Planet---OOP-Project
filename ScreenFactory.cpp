#include "ScreenFactory.hpp"
#include "MainScreen.hpp"
#include "GameOverScreen.hpp"
#include "PauseScreen.hpp"
#include "StartScreen.hpp"
#include "IntroScreen.hpp"
#include "Instructions.hpp"

ScreenFactory::ScreenFactory()
{
    scrns = NULL;
}
Screens *ScreenFactory::CreateScreen(std::string description, SDL_Texture *screentex, SDL_Texture *btntex)
{
    if (description == "mainscreen")
    {
        scrns = new MainScreen(screentex, btntex);
    }
    else if (description == "startscreen")
    {
        scrns = new StartScreen(screentex, btntex);
    }
    else if (description == "gameoverscreen")
    {
        scrns = new GameOverScreen(screentex, btntex);
    }
    else if (description == "pausescreen")
    {
        scrns = new PauseScreen(screentex, btntex);
    }
    else if (description == "introscreen")
    {
        scrns = new IntroScreen(screentex, btntex);
    }
    else if (description == "instructionsscreen")
    {
        scrns = new Instructions(screentex, btntex);
    }
    return scrns;
}
ScreenFactory::~ScreenFactory()
{
    delete scrns;
}
