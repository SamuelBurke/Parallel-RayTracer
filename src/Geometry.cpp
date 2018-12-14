#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"

#include <iostream>
#include <cmath>

Geometry::Geometry()
{
}

bool Geometry::RaySphereIntersect(std::shared_ptr<Ray> _ray, float &_t, glm::vec3 _sphereCentre, float _radius)
{
	// Using Pythagoras' Theorum to calculate the distance from the ray to the centre of the sphere.	
	glm::vec3 originToCentre = _ray->mOrigin - _sphereCentre;
	float b = 2 * glm::dot(originToCentre, _ray->mDirection);
	float c = glm::dot(originToCentre, originToCentre) - _radius * _radius;

	float distanceToCentre = b * b - 4 * c;
	if (distanceToCentre < 1e-4) // 1e-4 is a very very small value. 
	{
		return false;
	}

	distanceToCentre = sqrt(distanceToCentre);

	float x1 = -b - distanceToCentre;
	float x2 = -b + distanceToCentre;

	_t = (x1 < x2) ? x1 : x2; // Compare the two distances, return the smallest one.

	return true;
}