#include "Window.h"

#include <iostream>

int Window::m_width = 840;
int Window::m_height = 840;

void Window::InitWindow()
{
	m_window = NULL;
	m_surface = NULL;
	m_renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error: Cannot initalise SDL. SDL_Error: " << SDL_GetError();
	}

	m_window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	if (!m_renderer)
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
	SDL_RenderPresent(m_renderer);
}

void Window::UpdateSurface()
{
	SDL_UpdateWindowSurface(m_window);
}

void Window::DestroyWindow()
{
	SDL_DestroyWindow(m_window);
}


SDL_Window *Window::GetWindow()
{
	return m_window;
}

SDL_Renderer *Window::GetRenderer()
{
	return m_renderer;
}

SDL_Surface *Window::GetSurface()
{
	return m_surface;
}

int Window::GetWidth()
{
	return m_width;
}

int Window::GetHeight()
{
	return m_height;
}