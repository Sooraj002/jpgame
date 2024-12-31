#include <SDL.h>
#include <iostream>
#include "PlayerMove.h"

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

bool gameLoop(){
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 ) {
        switch (e.type) {
            case SDL_QUIT:
				return false;
            PlayerMove(e);
            
        }
    }
    return false;
}