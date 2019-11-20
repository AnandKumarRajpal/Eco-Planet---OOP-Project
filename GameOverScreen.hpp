#include <Screen.h>
#pragma once

class GameOverScreen : public Screen
{
public:
    gameOverScreen();
    void Render(long int &frame, SDL_Renderer *);
    virtual ~gameOverScreen();
    void Update(int score); //updates the game over screen according to the score of the level when the player loses
};