#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>
#include "GameObject.h"
#include <vector>
#include <memory>



class Game{
public:
    static bool gameIsRunning;


    static std::vector<std::unique_ptr<GameObject>> gameObjects;



    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static int Initialize();
    static void Clean();

    static void Start();
    static void Update();
    static void Render();
};





#endif