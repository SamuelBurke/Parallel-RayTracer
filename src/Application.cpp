#include "Application.h"

#include <iostream>

void Application::Initialise()
{
	mQuit = false;

	mCamera = std::make_shared<Camera>();
	mInput = std::make_shared<Input>();
	mWindow = std::make_shared<Window>();

	mSphere = std::make_shared<Sphere>();
	mSphere->SetPosition(glm::vec3(mWindow->GetWidth() * 0.2, mWindow->GetHeight() * 0.2, -150.0f)); // Centre point of the sphere.
	mSphere->SetRadius(100.0f);
	mSphere->SetColour(glm::vec3(1, 0, 0)); // Pass in between 0-1 for the colour. This gets converted to 0-255 later.
			
	mSphere2 = std::make_shared<Sphere>();
	mSphere2->SetPosition(glm::vec3(mWindow->GetWidth() * 0.5 + 160, mWindow->GetHeight() * 0.5 - 150, -150.0f)); // Centre point of the sphere.
	mSphere2->SetRadius(100.0f);
	mSphere2->SetColour(glm::vec3(0, 1, 0)); // Pass in between 0-1 for the colour. This gets converted to 0-255 later.

	mSphere3 = std::make_shared<Sphere>();
	mSphere3->SetPosition(glm::vec3(mWindow->GetWidth() * 0.5 - 200, mWindow->GetHeight() * 0.5 + 200, -150.0f));
	mSphere3->SetRadius(100.0f);
	mSphere3->SetColour(glm::vec3(0, 1, 1));

	mRayTracer.AddObject(mSphere);
	mRayTracer.AddObject(mSphere2);
	mRayTracer.AddObject(mSphere3);
	   	 
	mWindow->InitWindow();
}

void Application::Loop()
{
	for (int i = 0; i < mWindow->GetWidth(); i++)
	{
		for (int j = 0; j < mWindow->GetHeight(); j++)
		{
			std::shared_ptr<Ray> ray = mCamera->GenerateRay(glm::ivec2(i, j));
			glm::vec3 colour = (mRayTracer.TraceRay(ray, 2) * 255.0f); // convert colour value between 0-1 to 0-255.

			SDL_SetRenderDrawColor(mWindow->GetRenderer(), colour.x, colour.y, colour.z, 255);
			SDL_RenderDrawPoint(mWindow->GetRenderer(), i, j);
		}
	}

	
	while (!mQuit)
	{
		SDL_Event e = { 0 };

		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				mQuit = true;
			}
		}


		mInput->Tick();

		if (mInput->isKeyPressed(SDL_SCANCODE_ESCAPE))
		{
			mQuit = true;
		}

		//m_window.UpdateSurface();
		mWindow->PresentRenderer();
	}

	cleanup();
}

void Application::cleanup()
{
	mWindow->DestroyWindow();
}