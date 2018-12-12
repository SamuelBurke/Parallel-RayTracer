#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
	void InitWindow();
	void UpdateSurface();
	void PresentRenderer();

	void DestroyWindow();

	SDL_Window  *GetWindow();
	SDL_Surface *GetSurface();
	SDL_Renderer *GetRenderer();

	static int GetWidth();
	static int GetHeight();

private:
	static int mWidth;
	static int mHeight;

	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	SDL_Surface *mSurface;
};

#endif // !WINDOW_H
