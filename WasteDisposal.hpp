#include <SDL.h>
#include "Enemies.hpp"

class WasteDisposal : public Enemies
{
    public:
        WasteDisposal();
        ~WasteDisposal();
        void Dumpy();
};