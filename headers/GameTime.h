#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <SDL3/SDL.h> 

class GameTime{
public:
    static Uint64 currentFrame;
    static Uint64 pastFrame;
    static float deltaTime;
    static void CalculateDeltaTime();
};


#endif