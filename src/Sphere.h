#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

#include <glm/glm.hpp>
#include <memory>

class Ray;
class RayTracer;

//! Child class of object. Overrided the object's 'Shade' and 'GetNormal' function.
class Sphere : public Object
{
public:
	glm::vec3 Shade(std::shared_ptr<Ray> _ray, RayTracer& _rayTracer, glm::vec3(_intersection), int _count) override;
	glm::vec3 GetNormal(glm::vec3 _intersection) override;
};

#endif // !SPHERE_H
