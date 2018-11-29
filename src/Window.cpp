#include "Window.h"

#include <iostream>

int Window::m_width = 840;
int Window::m_height = 840;

void Window::InitWindow()
{
	m_window = NULL;
	m_surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error: Cannot initalise SDL. SDL_Error: " << SDL_GetError();
	}

	m_window = SDL_CreateWindow("RayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);

	if (m_window == NULL)
	{
		std::cout << "Error: Window could not be created. SDL_Error: " << SDL_GetError();
	}
	else
	{
		m_surface = SDL_GetWindowSurface(m_window);

		SDL_FillRect(m_surface, NULL, SDL_MapRGB(m_surface->format, 0, 0, 28));
	}
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

int Window::GetWidth()
{
	return m_width;
}

int Window::GetHeight()
{
	return m_height;
}