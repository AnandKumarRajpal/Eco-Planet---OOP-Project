#include "GameObject.hpp"

class Tree : public GameObject
{

public:
    Tree(SDL_Texture *, float, float, float, float, float, double, float);
    virtual ~Tree();
    void Update();

};