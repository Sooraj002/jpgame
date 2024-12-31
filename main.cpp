#include <iostream>
#include <SDL.h>
#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280


int main(){

    // SDL WINDOW AND SURFACE INITIALIZAITON
    SDL_Window * window =NULL;
    SDL_Surface* windowSurface = NULL;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "error in initializtion"  << SDL_GetError() << std::endl;
        return -1;
    } else {
        std::cout << "SDL initialized" << std::endl;
    }
    
    window = SDL_CreateWindow("Jumper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    if (!window ){
        std:: cout << "window not initialized" << std:: endl;
        SDL_Quit();
        return -1;
    }
    
    windowSurface = SDL_GetWindowSurface(window);
    
    if (!windowSurface){
        std:: cout << "windowSurface not initialized" << std:: endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    } 

    // GAME LOOP
    bool isRunning = true;
    SDL_Event e;
    while(isRunning){
        while (SDL_PollEvent(&e) != 0){
            switch(e.type){
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                    }
                        case (SDLK_w && SDLK_a:)
                            std::cout << "Go up and left" << std::endl;
                            break;
                        case SDLK_w:
                            std::cout << "Go up" << std::endl;
                            break;
                        case SDLK_a:
                            std::cout << "Go left" << std::endl;
                            break;
                        case SDLK_s:
                            std::cout << "Go down" << std::endl;
                            break;
                        case SDLK_d:
                            std::cout << "Go right" << std::endl;
                            break;
                    break;
            }
        }

    SDL_UpdateWindowSurface( window );
    
    }
    

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
