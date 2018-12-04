#include "RayTracer.h"
#include "Object.h"

#include <iostream>

RayTracer::RayTracer()
{
	m_blue = 0.109375f;
}

// Will test the incoming ray against all objects in the scene.
glm::vec3 RayTracer::TraceRay(std::shared_ptr<Ray> _ray)
{
	glm::vec3 colour = glm::vec3(0, 0, 0);
	// Find the first object the ray hits.
	// Go through every object in the scene:
	// Call the ray-sphere intersection function.
	// If it hits the objects, record the distance from the ray's origin to the intersection point.
	// Want the object with the shortest distance.

	// If the ray hits an object:
	// Call that object's shading method.
	// Return the pixel colour.

	// If the ray didn't hit an object:
	// Just return a background colour, as done below:
	glm::vec3 bkgcolour = glm::vec3(0, 0, m_blue);
	colour = bkgcolour;

	return colour;
}

void RayTracer::AddObject(std::shared_ptr<Object> _object)
{
	m_objects.push_back(_object);
}

void RayTracer::Debug()
{
	std::cout << m_objects.size() << std::endl;
}