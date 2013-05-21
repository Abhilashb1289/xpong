#include <SDL/SDL.h>
#include "constants.h"
#include <iostream>
#include "bg.h"

using namespace std;
void background::load_image ()
{
	bg_surface = SDL_LoadBMP (BG);
	if (bg_surface == NULL)
	{
		cout<<"Error loading background image";
		exit(0);
	}
	
	
}

void background::convert_to_display_format ()
{
	
	//bg_surface = SDL_DisplayFormat (temp_bg_surface);
}

void background::init_bg ()
{
	src_bg.x = 0;
	src_bg.y = 0;
	src_bg.h = bg_surface->h;
	src_bg.w = bg_surface->w;
	
	dest_bg.x = 0;
	dest_bg.y = 0;
	dest_bg.h = bg_surface->h;
	dest_bg.w = bg_surface->w;
}

void background::cleanup ()
{
	SDL_FreeSurface (temp_bg_surface);
	SDL_FreeSurface (bg_surface);
}

void background::init_screen ()
{
	screen = SDL_SetVideoMode (VIDEO_WIDTH,VIDEO_HEIGHT,VIDEO_BPP,SDL_DOUBLEBUF);
}
	
