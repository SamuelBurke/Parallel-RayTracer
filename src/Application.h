#ifndef APPLICATION_H
#define APPLICATION_H

#include "Program.h"

#include <memory>
#include <thread>
#include <mutex>

//! The core of this program.
/*! 
	Application contains the raytracer's loop, initalise function and the multithreading code.
	The functions are called from main.cpp
*/
class Application
{
public:
	// Initialise gets called first. This code is only run through once, and is used to set the position, colour and radius of each sphere.
	void Initialise();

	// Main loop. Once this function is called, it is never left until the program is over. Multi-threaded code happens at the start of this loop.
	void Loop();

	// cleanup is called at the end of loop, once the application is in the process of being terminated.
	void cleanup();

private:
	// Render function is used by the multiple threads in the program. Each 
	void Render(int _initialX, int _initialY, int finalX, int finalY);

	bool mQuit; // boolean variable used for the main while loop. Initalised as false. 

	std::vector<std::thread> mThreads; // int variable used to specify the number of threads the program will use.
	std::mutex mMutex;

	std::shared_ptr<Camera> mCamera; // pointer variable to the camera class, allows use of the 'GenerateRay' function.
	std::shared_ptr<Input> mInput; // pointer variable to the input class, allows the user to press Esc to quit the program.
	std::shared_ptr<Window> mWindow; // pointer variable to the window class, allows the window's initialisation code to run. Creates the window to be rendered to.

	RayTracer mRayTracer; // Allows the addition of objects(spheres) and the 'TraceRay' function to be used.

	std::shared_ptr<Sphere> mSphere; // Create a bunch of spheres. One to act as a light source, and the rest to demonstrate shading & reflections.
	std::shared_ptr<Sphere> mSphere2;
	std::shared_ptr<Sphere> mSphere3;
	std::shared_ptr<Sphere> mSphere4;
	std::shared_ptr<Sphere> mSphere5;
	std::shared_ptr<Sphere> mSphere6;
	std::shared_ptr<Sphere> mSphere7;
	std::shared_ptr<Sphere> mSphere8;
	std::shared_ptr<Sphere> mSphere9;

	std::shared_ptr<Sphere> mLightSphere;

	float mTime;
};

#endif // !APPLICATION_H
