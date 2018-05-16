#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace caveofprogramming;

int main() {


	srand(time(NULL));

	Screen screen;

	if (!screen.init()){
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;


	while (true) {



		int elapsed = SDL_GetTicks();

		// Update particles
		swarm.update(elapsed);
		// Draw particles

		unsigned char green = (unsigned char)((1 + sin(elapsed*0.0005)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed*0.0007)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed*0.0009)) * 128);

		const Particle * const pParticles = swarm.getParticles();
		for(int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x,y, red, green ,blue);
		}


/*
		for(int y=0; y < Screen::SCREEN_HEIGHT; y++){
			for(int x=0; x < Screen::SCREEN_WIDTH; x++){
				screen.setPixel(x,y,red,green,blue);

			}
		}

*/

		screen.boxBlur();

		// Draw the Screen
		screen.update();
		// Check for messages and events


		if(!screen.processEvents()){
			break;
		}



	}

	screen.close();

	return 0;
}
