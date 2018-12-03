#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

#include <glm/glm.hpp>
#include <memory>

class Ray;

class Sphere : public Object
{
public:
	Sphere();

	glm::vec3 Shade(std::shared_ptr<Ray> _ray, glm::vec3(_intersection));

private:
	glm::vec3 m_position;
	float m_radius;
	glm::vec3 m_colour;
};

#endif // !SPHERE_H
