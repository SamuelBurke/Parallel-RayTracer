#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "glm/glm.hpp"

#include <memory>

class Ray;
class Sphere;

class Geometry
{
public:
	Geometry();

	glm::vec3 ClosestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query);

	bool RaySphereIntersection(std::shared_ptr<Ray> _ray, glm::vec3 _sphereCentre, float _radius);

	//glm::vec3 

private:
};


#endif // !GEOMETRY_H
