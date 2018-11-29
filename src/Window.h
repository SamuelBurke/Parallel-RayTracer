#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
	void InitWindow();
	void UpdateSurface();

	void DestroyWindow();

	SDL_Window *GetWindow();

	static int GetWidth();
	static int GetHeight();

private:
	static int m_width;
	static int m_height;

	SDL_Window *m_window;
	SDL_Surface *m_surface;
};

#endif // !WINDOW_H
