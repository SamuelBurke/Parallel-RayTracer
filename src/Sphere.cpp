#include "Sphere.h"
#include "Ray.h"
#include "RayTracer.h"

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, RayTracer& _rayTracer, glm::vec3(_intersection), int _count)
{
	glm::vec3 colour = glm::vec3(0, 0, 0);
	glm::vec3 lightOrigin = glm::vec3(320.0f, 280.0f, 100.0f);

	glm::vec3 lightDirection = lightOrigin - _intersection; // The vector here is the light's origin point. -pi in order to get the direction of the light.
	glm::vec3 normal = GetNormal(_intersection);

	float dt = glm::dot(glm::normalize(lightDirection), glm::normalize(normal));

	glm::vec3 reflectColour = glm::vec3(0);
	if (_count > 0)
	{
		std::shared_ptr<Ray> reflectRay = std::make_shared<Ray>();

		reflectRay->mOrigin = _intersection + reflectRay->mDirection * 0.001f;
		reflectRay->mDirection = glm::reflect(-_ray->mDirection, normal);

		reflectColour = 0.5f * _rayTracer.TraceRay(reflectRay, _count - 1);
	}

	colour = ((mColour + glm::vec3(1.0f) * dt) * 0.55f) + reflectColour * mColour;

	return glm::clamp(colour, glm::vec3(0), glm::vec3(1));
}

glm::vec3 Sphere::GetNormal(glm::vec3 _pi)
{
	return (_pi - mPosition) / mRadius;
}