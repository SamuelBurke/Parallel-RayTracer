#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere()
{
}

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, glm::vec3(_intersection))
{
	glm::vec3 colour = glm::vec3(0, 0, 0);

	glm::vec3 lightDirection = glm::vec3(420.0, 420.0f, 0.0f) - _intersection; // The vector here is the light's origin point. -pi in order to get the direction of the light.
	glm::vec3 normal = GetNormal(_intersection);

	float dt = glm::dot(glm::normalize(lightDirection), glm::normalize(normal));

	colour = (mColour + glm::vec3(1.0f) * dt) * 0.5f;

	return glm::clamp(colour, glm::vec3(0), glm::vec3(1));
}

glm::vec3 Sphere::GetNormal(glm::vec3 _pi)
{
	return (_pi - mPosition) / mRadius;
}

void Sphere::SetPosition(glm::vec3 _position)
{
	mPosition = _position;
}

void Sphere::SetRadius(float _radius)
{
	mRadius = _radius;
}

void Sphere::SetColour(glm::vec3 _colour)
{
	mColour = _colour;
}

glm::vec3 Sphere::GetPosition()
{
	return mPosition;
}

float Sphere::GetRadius()
{
	return mRadius;
}

glm::vec3 Sphere::GetColour()
{
	return mColour;
}