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

	void SetPosition(glm::vec3 _position);
	void SetRadius(float _radius);
	void SetColour(glm::vec3 _colour);

	glm::vec3 GetPosition();
	float GetRadius();
	glm::vec3 GetColour();

	glm::vec3 GetNormal(glm::vec3 _pi);

private:
	glm::vec3 m_position;
	float m_radius;
	glm::vec3 m_colour;
};

#endif // !SPHERE_H
