#include "Application.h"

#include <iostream>

void Application::Initialise()
{
	mCamera = std::make_shared<Camera>(); // make_shared Allows use of each pointer.
	mInput = std::make_shared<Input>();
	mWindow = std::make_shared<Window>();

	mWindow->InitWindow();

	mQuit = false;


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

	mSphere7 = std::make_shared<Sphere>();
	mSphere7->SetPosition(glm::vec3(150.0f, 690.0f, -150.0f));
	mSphere7->SetRadius(120);
	mSphere7->SetColour(glm::vec3(0.9, 0.6, 0));

	mSphere8 = std::make_shared<Sphere>();
	mSphere8->SetPosition(glm::vec3(mWindow->GetWidth() * 0.5, 690.0f, -150.0f));
	mSphere8->SetRadius(120);
	mSphere8->SetColour(glm::vec3(0, 0.8, 0.5));

	mSphere9 = std::make_shared<Sphere>();
	mSphere9->SetPosition(glm::vec3(690.0f, 690.0f, -150.0f));
	mSphere9->SetRadius(120);
	mSphere9->SetColour(glm::vec3(0, 0.2, 0.5));

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
	mRayTracer.AddObject(mSphere7);
	mRayTracer.AddObject(mSphere8);
	mRayTracer.AddObject(mSphere9);	   	 
}

// Takes in an initalX/Y & finalX/Y, each thread will have a different inital x/y and final x/y, allowing threads to work on different parts of the screen.
void Application::Render(int _initialX, int _initalY, int _finalX, int _finalY)
{
	for (int i = _initialX; i < _finalX; i++) // Width values.
	{
		for (int j = _initalY; j < _finalY; j++) // Height values.
		{
			std::shared_ptr<Ray> ray = mCamera->GenerateRay(glm::ivec2(i, j)); // Create a new ray for the pixel coordinates currently at.
			glm::vec3 colour = (mRayTracer.TraceRay(ray, 2) * 255.0f); // Convert the colour value returned from 'TraceRay' from 0-1 to 0-255

			mMutex.lock();
			SDL_SetRenderDrawColor(mWindow->GetRenderer(), colour.x, colour.y, colour.z, 255); // Sets the colour using the colour variable set above.
			SDL_RenderDrawPoint(mWindow->GetRenderer(), i, j); // Draws the pixel.
			mMutex.unlock();
		}
	}
}

void Application::Loop()
{  
	//Render(0, 0, mWindow->GetWidth(), mWindow->GetHeight()); // Without Multithreading.

	int final = mWindow->GetWidth() * 0.5f;
	for (size_t x = 0; x < mWindow->GetWidth(); x += final) // X value.
	{
		for (size_t y = 0; y < mWindow->GetHeight(); y += final) // Y value.
		{
			//Creates a thread, calls the 'Render' function from the thread, and pushes the thread back to the 'mThreads' variable.
			mThreads.push_back(std::thread(&Application::Render, this, x, y, x + final, y + final)); 
		}
	}
	std::cout << "Number of threads: " << mThreads.size() << std::endl; // Outputs the number of threads to the console.

	for (size_t i = 0; i < mThreads.size(); i++)
	{
		mThreads.at(i).join(); // Join each thread back to this loop.
	}
	mThreads.clear(); // Clear the vector after they have all been used.

	mTime = SDL_GetTicks(); // Fetch the number of milliseconds since SDL was initalised.
	mTime = mTime / 1000.0f; // Divide by 1000 to convert to seconds.

	std::cout << "Time since initialisation: " << mTime << " seconds" << std::endl; // Outputs the time taken to render the scene.
	
	while (!mQuit) // Main loop - Since the program only renders once, this just keeps the window open.
	{
		SDL_Event e = { 0 };

		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) // Quits if the user clicks the red X in the corner of the window.
			{
				mQuit = true;
			}
		}

		mInput->Tick(); // Call 'Tick' of the input, allows the following function:

		if (mInput->isKeyPressed(SDL_SCANCODE_ESCAPE)) // If the current key variable of Input matches this Esc keycode, true will be returned and the program will end.
		{
			mQuit = true;
		}

		mWindow->PresentRenderer(); // Present the renderer each frame. This doesn't need to be called in this loop, but would be if anything was to update during the application's run time.
	}

	cleanup(); // Reaching this point means the main loop has been left, and the program needs to close.
}

void Application::cleanup()
{
	mWindow->DestroyWindow(); // Deletes the window and calls the SDL_Quit function.
	SDL_Quit();
}