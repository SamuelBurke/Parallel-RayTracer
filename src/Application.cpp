#include "Application.h"
#include "Program.h"

#include <iostream>

void Application::Initialise()
{
	m_quit = false;

	m_camera = std::make_shared<Camera>();
	m_input = std::make_shared<Input>();
	m_object = std::make_shared<Object>();
	m_rayTracer = std::shared_ptr<RayTracer>();
	m_window = std::make_shared<Window>();

	m_window->InitWindow();
}

void Application::Loop()
{
	for (int i = 0; i < m_window->GetWidth(); i++)
	{
		for (int j = 0; j < m_window->GetHeight(); j++)
		{
			std::shared_ptr<Ray> ray = m_camera->GenerateRay(glm::vec2(i, j));
			glm::vec3 colour = m_rayTracer->TraceRay(ray);


			SDL_SetRenderDrawColor(m_window->GetRenderer(), colour.x, colour.y, colour.z, 255);
			SDL_RenderDrawPoint(m_window->GetRenderer(), i, j);
		}
	}

	
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

		m_input->Tick();

		if (m_input->isKeyPressed(SDL_SCANCODE_ESCAPE))
		{
			m_quit = true;
		}

		//m_window.UpdateSurface();
		m_window->PresentRenderer();
	}

	cleanup();
}

void Application::cleanup()
{
	m_window->DestroyWindow();
}