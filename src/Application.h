#ifndef APPLICATION_H
#define APPLICATION_H

#include "Program.h"

#include <memory>

class Application
{
public:
	void Initialise();
	void Loop();
	void cleanup();

private:
	bool mQuit;

	std::shared_ptr<Camera> mCamera;
	std::shared_ptr<Input> mInput;
	std::shared_ptr<Window> mWindow;
	//std::shared_ptr<RayTracer> m_rayTracer;

	RayTracer mRayTracer;

	//Sphere m_sphere;
	//Sphere m_sphere2;

	std::shared_ptr<Sphere> mSphere;
	std::shared_ptr<Sphere> mSphere2;
	std::shared_ptr<Sphere> mSphere3;

	//std::shared_ptr<Sphere> m_lightSphere;

};

#endif // !APPLICATION_H
