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
	glm::vec3 originToCentre = _ray->mOrigin - _sphereCentre;
	float b = 2 * glm::dot(originToCentre, _ray->mDirection);
	float c = glm::dot(originToCentre, originToCentre) - _radius * _radius;

	float distanceToCentre = b * b - 4 * c;
	if (distanceToCentre < 1e-4)
	{
		return false;
	}

	distanceToCentre = sqrt(distanceToCentre);

	float t0 = -b - distanceToCentre;
	float t1 = -b + distanceToCentre;

	_t = (t0 < t1) ? t0 : t1;
	return true;
}