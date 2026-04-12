#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>


extern double deltaTime;

void GetInputs(SDL_Event* event);



void Start(SDL_Renderer* renderer);
void Update();
void Render(SDL_Renderer* renderer);





#endif