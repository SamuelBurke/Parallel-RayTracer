#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "glm/glm.hpp"

#include <memory>

class Ray;
class Sphere;

//! Deals with the various geometry in the application.
class Geometry
{
public:
	Geometry();

	// Called for each object in the application. Returns whether or not the ray intersected, and sets the 't' variable.
	bool RaySphereIntersect(std::shared_ptr<Ray> _ray, float &_t, glm::vec3 _sphereCentre, float _radius);
};


#endif // !GEOMETRY_H
