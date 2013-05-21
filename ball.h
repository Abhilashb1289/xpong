#include <SDL/SDL.h>




class ball
{
	private:
	SDL_Surface *temp_ball_surface;
	public:
	
	SDL_Rect src_ball,dest_ball;
	int dx,dy;
	
	SDL_Surface *ball_surface;
	
	void load_image (void);//
	void convert_to_display_format (void);//
	void init_ball ();
	void draw_ball (void);
	void cleanup (void);
};
	
	
