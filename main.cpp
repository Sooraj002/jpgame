#include <iostream>
#include <SDL.h>
#define WIDTH 900
#define HEIGHT  600

int main(int argc, char *argv[]){ 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create an SDL window
    SDL_Window *window = SDL_CreateWindow("GAME_Window", 
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                          WIDTH, HEIGHT, 0);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    SDL_Surface* surface = SDL_GetWindowSurface(window); 
    SDL_Rect rect = (SDL_Rect){WIDTH/2,HEIGHT/2,50,50};
    SDL_FillRect(surface, &rect, 0xffffffff);
    SDL_UpdateWindowSurface(window);
    // Wait until the window is closed
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    // Clean up and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
