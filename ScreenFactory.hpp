#include "Screens.hpp"
// class MainScreen;
// class StartScreen;
// class GameOverScreen;
// class PauseScreen;
// class Instructions;
// class IntroScreen;

class ScreenFactory
{
    Screens *scrns;

public:
    ScreenFactory();
    ~ScreenFactory();
    Screens *CreateScreen(std::string, SDL_Texture *, SDL_Texture *);
};