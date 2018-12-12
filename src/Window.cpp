#include "Window.h"

#include <iostream>

int Window::mWidth = 840;
int Window::mHeight = 840;

void Window::InitWindow()
{
	mWindow = NULL;
	mSurface = NULL;
	mRenderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error: Cannot initalise SDL. SDL_Error: " << SDL_GetError();
	}

	mWindow = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth, mHeight, SDL_WINDOW_SHOWN);

	mRenderer = SDL_CreateRenderer(mWindow, -1, 0);

	if (!mRenderer)
	{
		std::cout << "Error: Renderer is empty. SDL_Error: " << SDL_GetError();
	}

	//if (m_window == NULL)
	//{
	//	std::cout << "Error: Window could not be created. SDL_Error: " << SDL_GetError();
	//}
	//else
	//{
	//	m_surface = SDL_GetWindowSurface(m_window);

	//	SDL_FillRect(m_surface, NULL, SDL_MapRGB(m_surface->format, 0, 0, 28));
	//}

	
}

void Window::PresentRenderer()
{
	SDL_RenderPresent(mRenderer);
}

void Window::UpdateSurface()
{
	SDL_UpdateWindowSurface(mWindow);
}

void Window::DestroyWindow()
{
	SDL_DestroyWindow(mWindow);
}


SDL_Window *Window::GetWindow()
{
	return mWindow;
}

SDL_Renderer *Window::GetRenderer()
{
	return mRenderer;
}

SDL_Surface *Window::GetSurface()
{
	return mSurface;
}

int Window::GetWidth()
{
	return mWidth;
}

int Window::GetHeight()
{
	return mHeight;
}