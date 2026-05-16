#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>



class Game{
public:
    static bool gameIsRunning;

    static void GetInputs();
    static void Start(SDL_Renderer* renderer);
    static void Update();
    static void Render(SDL_Renderer* renderer);
};





#endif