#include "Input.h"

#include <SDL3/SDL.h>

SDL_Event Input::event;
const bool* Input::keyStates;


float Input::InputDirection(SDL_Scancode positive, SDL_Scancode negative){

    float direction = 0;
    if(Input::keyStates[positive]) direction += 1.0f;

    if(Input::keyStates[negative]) direction -= 1.0f;

    return direction;
}