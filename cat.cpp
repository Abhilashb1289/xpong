#include <SDL/SDL.h> //SDL library
#include "constants.h" //Values which are constant throught out program execution
#include "ball.h" //The ball declaration
#include "bg.h"	//Background declaration
#include <iostream> //For 'cout' when an error occurs 
#include "SDL_collide.h" //Collision detection

using namespace std;


int main ()
{

	SDL_Init (SDL_INIT_VIDEO); //Initiate video mode
	atexit (SDL_Quit); //Call SDL_Quit when the program exits
	
	background bg_default; //bg_default-instance of class background defined in bg.h, bg.cpp
	ball balls[MAX_BALLS]; //Create a number of ball objects
	
	bg_default.load_image (); //Load the background image
	bg_default.convert_to_display_format (); //Convert it to blit friendly format
	bg_default.init_screen (); //Initiate screen
	bg_default.init_bg (); //Initiate the background image
	
	int i,j,k;
	
	for (i=0; i < MAX_BALLS ; i++) //Initiate everything for balls
	{
		balls[i].load_image ();
		balls[i].convert_to_display_format ();
		balls[i].init_ball ();
		
	}
	
	for (i = 0; i < FRAMES; i++) //Loop till FRAMES
	{
		SDL_BlitSurface(bg_default.bg_surface,&bg_default.src_bg,bg_default.screen,&bg_default.dest_bg); //Blit the background
		for (j = 0; j < MAX_BALLS ; j++) //Apply basic physics and Blit every single ball
		{
			if (balls[j].dest_ball.x < 0 || balls[j].dest_ball.x > bg_default.screen->w-10)
			{
				balls[j].dx = -balls[j].dx;
			}
			if (balls[j].dest_ball.y < 0 || balls[j].dest_ball.y > bg_default.screen->h-10)
			{
				balls[j].dy = -balls[j].dy;
			}
			for (k = 0; k < MAX_BALLS; k++) //If two balls collide then send them in opposite directions
			{
				if ( SDL_CollideBoundingBox(balls[j].dest_ball,balls[k].dest_ball) )
				{
					balls[j].dx = -balls[j].dx;
					balls[j].dy = -balls[j].dy;
					balls[k].dx = -balls[k].dx;
					balls[k].dy = -balls[k].dy;
				}
			}
			SDL_BlitSurface(balls[j].ball_surface,&balls[j].src_ball,bg_default.screen,&balls[j].dest_ball); //Blit the balls
			balls[j].draw_ball (); //Add dx,dy to dest_ball
		}
		

		
		SDL_Flip(bg_default.screen); //Flip the surface screen
		
		
	}
	
	for (i = 0; i < MAX_BALLS; i++)
	{
		balls[i].cleanup (); //Free memory
	}
	bg_default.cleanup (); //Same
	return 0; //All done :)
	
}
