#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

//! Handles all window related code. Called from application.
class Window
{
public:
	void InitWindow();
	void PresentRenderer();

	void DestroyWindow();

	SDL_Window  *GetWindow();
	SDL_Renderer *GetRenderer();

	static int GetWidth();
	static int GetHeight();

private:
	static int mWidth;
	static int mHeight;

	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
};

#endif // !WINDOW_H
