#include <iostream>
#include <SDL.h>
#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280


// Function Declarations
bool initialize(SDL_Window *&window, SDL_Surface *&windowSurface);
void cleanUp(SDL_Window *window);

int main() {
    // Initialize SDL and create window
    SDL_Window* window = nullptr;
    SDL_Surface* windowSurface = nullptr;

    if (!initialize(window, windowSurface)) {
        return -1;
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
    
  cleanUp(window);  
  return 0;
}



// SDL Initialization Function
bool initialize(SDL_Window *&window, SDL_Surface *&windowSurface) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Error in initialization: " << SDL_GetError() << std::endl;
        return false;
    }

    std::cout << "SDL initialized" << std::endl;

    window = SDL_CreateWindow("Jumper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        std::cerr << "Window not initialized: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    windowSurface = SDL_GetWindowSurface(window);
    if (!windowSurface) {
        std::cerr << "Window surface not initialized: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

// Clean up Function
void cleanUp(SDL_Window *window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
