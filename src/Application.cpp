#include "Application.h"

void Application::Initialise()
{
	m_quit = false;

	m_window.InitWindow();
}

void Application::Loop()
{
	while (!m_quit)
	{
		SDL_Event e = { 0 };

		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				m_quit = true;
			}
		}

		m_input.Tick();
		if (m_input.isKeyPressed(SDL_SCANCODE_ESCAPE))
		{
			m_quit = true;
		}

		m_window.UpdateSurface();
	}

	cleanup();
}

void Application::cleanup()
{
	m_window.DestroyWindow();
}