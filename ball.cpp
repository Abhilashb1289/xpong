#include <SDL/SDL.h>
#include <cstdlib>
#include "ball.h"
#include "constants.h"
#include <iostream>
using namespace std;

void ball::load_image ()
{
	temp_ball_surface = SDL_LoadBMP (BALL);	
	if (temp_ball_surface == NULL)
	{
		cout<<endl<<"Error loading ball"<<endl;
		exit(0);
	}
}

void ball::convert_to_display_format ()
{
	ball_surface = SDL_DisplayFormat (temp_ball_surface);
}

void ball::init_ball ()
{
	src_ball.x = 0;
	src_ball.y = 0;
	src_ball.h = ball_surface->h;
	src_ball.w = ball_surface->w;
	dest_ball.x = rand()%VIDEO_WIDTH;
	dest_ball.y = rand()%VIDEO_HEIGHT;
	dest_ball.h = ball_surface->h;
	dest_ball.w = ball_surface->w;
	
	dx = rand()%BALL_SPEED;
	dy = rand()%BALL_SPEED;
}

void ball::draw_ball ()
{
	dest_ball.x += dx;
	dest_ball.y += dy;
}

void ball::cleanup ()
{
	SDL_FreeSurface (ball_surface);
	SDL_FreeSurface (temp_ball_surface);
}

