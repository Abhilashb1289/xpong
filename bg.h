#include <SDL/SDL.h>

class background
{
	private:
	 SDL_Surface *temp_bg_surface;
	public:
	 SDL_Rect src_bg,dest_bg;
	 SDL_Surface *bg_surface;
	 SDL_Surface *screen;
	 
	 void load_image (void);
	 void convert_to_display_format (void);
	 void init_screen (void);
	 void init_bg (void);
	 void cleanup (void);
};
