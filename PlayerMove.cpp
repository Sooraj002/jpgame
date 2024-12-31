#include <SDL.h>
#include <iostream>
void PlayerMove(SDL_Event e){
    if (e.type == SDL_KEYDOWN){
        switch (e.key.keysym.sym) {
                    case SDLK_w:
                        std:: cout << "we go up" << std::endl;
                        break;
                    case SDLK_s:
                        std:: cout << "we go down" << std::endl;
                        break;
                    case SDLK_a:
                        std:: cout << "we go left" << std::endl;
                        break;
                    case SDLK_d:
                        std:: cout << "we go right" << std::endl;
                        break;
                    
                }
    }
                
}