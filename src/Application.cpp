#include "Application.h"

#include <iostream>

void Application::Initialise()
{
	m_quit = false;

	m_camera = std::make_shared<Camera>();
	m_input = std::make_shared<Input>();
	m_window = std::make_shared<Window>();

	m_debugSphere = std::make_shared<Sphere>();
	m_debugSphere->SetPosition(glm::vec3(150.0f, 600.0f, -150.0f));
	m_debugSphere->SetRadius(50.0f);
	m_debugSphere->SetColour(glm::vec3(0, 1, 1));


	m_sphere = std::make_shared<Sphere>();
	m_sphere->SetPosition(glm::vec3(m_window->GetWidth() * 0.5, m_window->GetHeight() * 0.5, -150.0f)); // Centre point of the sphere.
	m_sphere->SetRadius(100.0f);
	m_sphere->SetColour(glm::vec3(1, 0, 0)); // Pass in between 0-1 for the colour. This gets converted to 0-255 later.
			
	m_sphere2 = std::make_shared<Sphere>();
	m_sphere2->SetPosition(glm::vec3(m_window->GetWidth() * 0.5 + 160, m_window->GetHeight() * 0.5 - 150, -150.0f)); // Centre point of the sphere.
	m_sphere2->SetRadius(50.0f);
	m_sphere2->SetColour(glm::vec3(0, 1, 0)); // Pass in between 0-1 for the colour. This gets converted to 0-255 later.

	m_rayTracer.AddObject(m_debugSphere);


	m_rayTracer.AddObject(m_sphere);
	m_rayTracer.AddObject(m_sphere2);




	m_window->InitWindow();
}

void Application::Loop()
{
	for (int i = 0; i < m_window->GetWidth(); i++)
	{
		for (int j = 0; j < m_window->GetHeight(); j++)
		{
			std::shared_ptr<Ray> ray = m_camera->GenerateRay(glm::ivec2(i, j));
			glm::vec3 colour = (m_rayTracer.TraceRay(ray) * 255.0f); // convert colour value between 0-1 to 0-255.

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

		m_rayTracer.Debug();

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