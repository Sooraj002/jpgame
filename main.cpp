#include <SDL.h>
#include <iostream>
#define STEP 50

// Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

class Physics {
    int gravity;
public:
    Physics() {
        gravity = 0.5;
    }
};

class Player {
private:
    int x, y, velocityX, velocityY, height, width;
public: 
    Player(int xVal, int yVal){
        x = xVal;
        y = yVal;
        velocityX = STEP;
        velocityY = 0;
        height = 100;
        width = 100;
    }
    void keydownEvents(SDL_Event e) {
        switch (e.key.keysym.sym) {
            case SDLK_a:
                move(-1);
                std::cout << "moving left" << std::endl;
                break;
            case SDLK_d:
                move(1);
                std::cout << "moving right" << std::endl;
                break;
        }
    }
    void renderPlayer(SDL_Surface* surface) {
        SDL_Rect rect = {x, y, width, height};
        SDL_FillRect(surface, &rect, 0xffffffff);
    }
    void move(int direction) {
        x += velocityX * direction;
    }
    void jump() {
        // jump logic
    }
};

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
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
            return false;
        }

        // Get window surface
        screenSurface = SDL_GetWindowSurface(window);
        return true;
    }

    SDL_Window* getWindow() {
        return window;
    }

    SDL_Surface* getSurface() {
        return screenSurface;
    }

    void renderEmptyScreen() {
        if (!window || !screenSurface) {
            std::cerr << "Window or surface is not initialized.\n";
            return;
        }

        // Fill the surface white
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0x1d, 0x1d, 0x1d));
    }

    void eventLoop() {
        SDL_Event e;
        bool quit = false;

        Player mainCharacter(100,200);
        //int* state = SDL_GetKeyboardState();
        while (!quit) {
            while (SDL_PollEvent(&e)) {
                switch (e.type) {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        mainCharacter.keydownEvents(e);
                }
            }

            // Update the surface, by updating it with empty screen and then the latest state of the game
            renderEmptyScreen();
            mainCharacter.renderPlayer(screenSurface);
            SDL_UpdateWindowSurface(window);
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
    app.renderEmptyScreen();
    app.eventLoop();

    return 0;
}
