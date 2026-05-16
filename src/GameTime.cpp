#include "GameTime.h"   


float GameTime::deltaTime;
Uint64 GameTime::currentFrame;
Uint64 GameTime::pastFrame;





void GameTime::CalculateDeltaTime(){
    GameTime::currentFrame = SDL_GetPerformanceCounter();
    GameTime::deltaTime = (float)(currentFrame - pastFrame) / (float)SDL_GetPerformanceFrequency();
    GameTime::pastFrame = SDL_GetPerformanceCounter();
}