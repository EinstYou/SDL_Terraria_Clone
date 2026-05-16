#include "Input.h"

#include <SDL3/SDL.h>

SDL_Event Input::event;



float Input::InputDirection(SDL_Scancode positive, SDL_Scancode negative){

    const bool* keyStates = SDL_GetKeyboardState(NULL);
    float direction = 0;
    if(keyStates[positive]) direction += 1.0f;

    if(keyStates[negative]) direction -= 1.0f;

    return direction;
}