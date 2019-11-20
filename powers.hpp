#include <string.h>
#include "player.hpp"

class powers : public player
{
private:
    string feature;
    int life;

public:
    powers();
    ~powers();
    virtual void Render(SDL_Renderer *gRenderer) = 0;
};
    )