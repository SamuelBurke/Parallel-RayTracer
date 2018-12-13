#include "Application.h"

#include <iostream>

void Application::Initialise()
{
	mQuit = false;

	mCamera = std::make_shared<Camera>(); // make_shared Allows use of each pointer.
	mInput = std::make_shared<Input>();
	mWindow = std::make_shared<Window>();

	mSphere = std::make_shared<Sphere>();
	mSphere->SetPosition(glm::vec3(150.0f, 150.0f, -150.0f)); // Centre point of the sphere.
	mSphere->SetRadius(100.0f);
	mSphere->SetColour(glm::vec3(1, 0, 0)); // Pass in between 0-1 for the colour. This gets converted to 0-255 later.
			
	mSphere2 = std::make_shared<Sphere>();
	mSphere2->SetPosition(glm::vec3(mWindow->GetWidth() * 0.5, 150.0f, -150.0f));
	mSphere2->SetRadius(100.0f);
	mSphere2->SetColour(glm::vec3(0, 1, 0)); 

	mSphere3 = std::make_shared<Sphere>();
	mSphere3->SetPosition(glm::vec3(690.0f, 150.0f, -150.0f));
	mSphere3->SetRadius(100.0f);
	mSphere3->SetColour(glm::vec3(0, 1, 1));

	mSphere4 = std::make_shared<Sphere>();
	mSphere4->SetPosition(glm::vec3(150.0f, mWindow->GetHeight() * 0.5, -150.0f));
	mSphere4->SetRadius(100.0f);
	mSphere4->SetColour(glm::vec3(1, 1, 0));

	mSphere5 = std::make_shared<Sphere>();
	mSphere5->SetPosition(glm::vec3(mWindow->GetWidth() * 0.5, mWindow->GetHeight() * 0.5, -150.0f));
	mSphere5->SetRadius(100.0f);
	mSphere5->SetColour(glm::vec3(1, 0, 1));

	mSphere6 = std::make_shared<Sphere>();
	mSphere6->SetPosition(glm::vec3(690.0f, mWindow->GetHeight() * 0.5, -150.0f));
	mSphere6->SetRadius(100.0f);
	mSphere6->SetColour(glm::vec3(0, 0, 1));

	mLightSphere = std::make_shared<Sphere>();
	mLightSphere->SetPosition(glm::vec3(320.0f, 280.0f, -10.0f));
	mLightSphere->SetRadius(25.0f);
	mLightSphere->SetColour(glm::vec3(0.5, 0.9, 0.9));

	mRayTracer.AddObject(mLightSphere);

	mRayTracer.AddObject(mSphere);
	mRayTracer.AddObject(mSphere2);
	mRayTracer.AddObject(mSphere3);
	mRayTracer.AddObject(mSphere4);
	mRayTracer.AddObject(mSphere5);
	mRayTracer.AddObject(mSphere6);

	   	 
	mWindow->InitWindow();
}

// Takes in an initalX/Y & finalX/Y 
void Application::Render(int _initialX, int _initalY, int _finalX, int _finalY)
{
	for (int i = _initialX; i < _finalX; i++)
	{
		for (int j = _initalY; j < _finalY; j++)
		{
			std::shared_ptr<Ray> ray = mCamera->GenerateRay(glm::ivec2(i, j));
			glm::vec3 colour = (mRayTracer.TraceRay(ray, 2) * 255.0f); // convert colour value between 0-1 to 0-255.

			mMutex.lock();
			SDL_SetRenderDrawColor(mWindow->GetRenderer(), colour.x, colour.y, colour.z, 255);
			SDL_RenderDrawPoint(mWindow->GetRenderer(), i, j);
			mMutex.unlock();

		}
	}
}

void Application::Loop()
{
	std::vector<std::thread> t;

	for (size_t x = 0; x < mWindow->GetWidth(); x += 840)
	{
		for (size_t y = 0; y < mWindow->GetHeight(); y += 840)
		{
			t.push_back(std::thread(&Application::Render, this, x, y, x + 840, y + 840));
		}
	}

	for (size_t i = 0; i < t.size(); i++)
	{
		t.at(i).join();
	}

	t.clear();


	
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

		mWindow->PresentRenderer();
	}

	cleanup();
}

void Application::cleanup()
{
	mWindow->DestroyWindow();
	SDL_Quit();
}