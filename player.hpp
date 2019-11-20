#include "GameObject.hpp"

class player : public GameObject
{
private:
    int direction;
    int lives;

public:
    player(LTexture *, float, float);
    void Move();
    void punch();
    void setDirection(int);
    int getDirection();
    void Render(SDL_Renderer *gRenderer);
    void slide();
    void attack(Enemies *);
    void setLives(int lives) { this->lives = lives; }
    int getLives() { return lives; }
    virtual ~player();
};
