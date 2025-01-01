
#include <SDL.h>
#include <iostream>

// Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

class SDLApp {
private:
    // The window we'll be rendering to
    SDL_Window* window = nullptr;

    // The surface contained by the window
    SDL_Surface* screenSurface = nullptr;

public:
    SDLApp() = default;

    ~SDLApp() {
        cleanUp();
    }

    bool initialize() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
            return false;
        }

        // Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
            return false;
        }

        // Get window surface
        screenSurface = SDL_GetWindowSurface(window);
        return true;
    }

    void render() {
        if (!window || !screenSurface) {
            std::cerr << "Window or surface is not initialized.\n";
            return;
        }

        // Fill the surface white
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

        // Update the surface
        SDL_UpdateWindowSurface(window);
    }

    void eventLoop() {
        SDL_Event e;
        bool quit = false;

        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
        }
    }

    void cleanUp() {
        if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }

        SDL_Quit();
    }
};

int main(int argc, char* args[]) {
    SDLApp app;

    if (!app.initialize()) {
        return 1;
    }

    app.render();
    app.eventLoop();

    return 0;
}
