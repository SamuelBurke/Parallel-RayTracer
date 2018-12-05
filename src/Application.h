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
	bool m_quit;

	std::shared_ptr<Camera> m_camera;
	std::shared_ptr<Input> m_input;
	std::shared_ptr<Window> m_window;
	//std::shared_ptr<RayTracer> m_rayTracer;

	RayTracer m_rayTracer;

	//Sphere m_sphere;
	std::shared_ptr<Sphere> m_sphere;
	//std::shared_ptr<Sphere> m_sphere2;

};

#endif // !APPLICATION_H
