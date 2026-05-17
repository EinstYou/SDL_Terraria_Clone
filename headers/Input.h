#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>


class Input{
public:
    static const bool* keyStates;
    static SDL_Event event;
    static float InputDirection(SDL_Scancode positive, SDL_Scancode negative);
};



#endif