#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "glm/glm.hpp"

#include <memory>

class Ray;

class Geometry
{
public:
	glm::vec3 ClosestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query);

private:
	Geometry();
};


#endif // !GEOMETRY_H
