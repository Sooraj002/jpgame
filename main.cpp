#include <iostream>
#include <SDL.h>
#define WIDTH 900
#define HEIGHT  600
#define STEP 5 

class Player{
	int x;
	int y;
	int velocityX;
	int velocityY;

	public:
	Player(int initialX, int initialY, int initialVelocityX, int initialVelocityY){
		velocityX = initialVelocityX;
		velocityY = initialVelocityY;
		x = initialX;
		y = initialY;
	}
	int getX() {return x;}
	int getY() {return y;}
	void moveUp(){
		y -= STEP; 
	}
	void moveDown(){
		y += STEP;
	}
	void moveLeft(){
		x -= STEP;
	}
	void moveRight(){
		x += STEP;
	}	
};

void updatePlayer(Player player, SDL_Surface* surface, SDL_Window* window){
	int x = player.getX();
	int y = player.getY();
	SDL_Rect BlackScreen = (SDL_Rect){0, 0, WIDTH, HEIGHT};
	SDL_FillRect(surface,&BlackScreen, 0x00000000);
	SDL_Rect newPosition = (SDL_Rect){x,y,50,50};
	SDL_FillRect(surface, &newPosition, 0xffffffff);
	SDL_UpdateWindowSurface(window);
}

int main(int argc, char *argv[]){
	Player p1(200,100,0,0);

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
	SDL_Rect rect = (SDL_Rect){p1.getX(),p1.getY(),50,50};
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
			if (e.type == SDL_KEYDOWN){
				char keyInput = e.key.keysym.sym;
				switch(keyInput)
				{
					case 'w':
						p1.moveUp();
						updatePlayer(p1, surface, window);
						break;
					case 's':
						p1.moveDown();
						updatePlayer(p1, surface, window);
						break;
					case 'a':
						p1.moveLeft();
						updatePlayer(p1, surface, window);
						break;
					case 'd':
						p1.moveRight();
						updatePlayer(p1, surface, window);
						break;
					case ' ':
						p1.moveUp();
						updatePlayer(p1, surface, window);
						SDL_Delay(100);
						p1.moveDown();
						updatePlayer(p1, surface, window);
						break;
				}
			}


			//	SDL_Rect blackScreen = (SDL_Rect){0,0,WIDTH,HEIGHT};
		}
	}

    // Clean up and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
