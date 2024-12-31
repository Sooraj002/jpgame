#include <SDL.h>
#include <iostream>
#include "gameLoop.h"

// g++ main.cpp gameLoop.cpp -o game
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char ** args){
    SDL_Surface* winSurface = NULL;
    SDL_Window* window = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "SDL Initialized Successfully!!";
    window = SDL_CreateWindow("Title",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    if (!window){
        std::cout << "SDL Window Failed to Initialize: " << SDL_GetError() << std::endl;
        system("pause");
        return -1;
    }
    
    winSurface = SDL_GetWindowSurface(window);

    if (!winSurface){
        std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
        system("pause");
	    return -1;
    }

    // SDL Fill Rectangle Method
    SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 0, 255, 255));
    
    // SDL Update Window Function
    while(gameLoop()){
        SDL_UpdateWindowSurface( window );
    }
}
