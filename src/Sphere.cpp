#include "Sphere.h"
#include "Ray.h"
#include "RayTracer.h"

Sphere::Sphere()
{
}

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, RayTracer& _rayTracer, glm::vec3(_intersection), int _count)
{
	glm::vec3 colour = glm::vec3(0, 0, 0);
	glm::vec3 lightDirection = glm::vec3(0.0f, 0.0f, 0.0f) - _intersection; // The vector here is the light's origin point. -pi in order to get the direction of the light.
	glm::vec3 normal = GetNormal(_intersection);

	float dt = glm::dot(glm::normalize(lightDirection), glm::normalize(normal));

	colour = (mColour + glm::vec3(1.0f) * dt) * 0.5f;

	//glm::vec3 lightPosition = glm::vec3(0);
	//glm::vec3 lightDirection = glm::vec3(0.0f, 0.0f, 0.0f) - _intersection;

	//glm::vec3 lightColour = { 1.0f, 1.0f, 1.0f };
	//float specularInt = 1.0f; // Specular Intensity.

	////Ambient
	//glm::vec3 ambientColour = glm::vec3(1.0f, 0.0f, 0.0f);
	//float ambientStr = 0.1f;
	//glm::vec3 ambient = ambientStr * mColour;

	////Diffuse
	//lightDirection = glm::normalize(lightDirection);
	//glm::vec3 normal = GetNormal(_intersection);
	//float diffuseColour = glm::dot(lightDirection, normal);

	////Specular
	//glm::vec3 reflect = glm::reflect(-lightDirection, normal);
	//glm::vec3 cameraView = glm::normalize(-_ray->mDirection);
	////float specularColour = glm::pow(glm::max(glm::dot(cameraView, glm::normalize(reflect)), 0.0f), 50);
	//float specularColour = glm::pow(glm::dot(cameraView, glm::normalize(reflect)), 50);
	//specularColour *= specularInt;


	//glm::vec3 reflectColour = glm::vec3(0);
	//if (_count > 0)
	//{
	//	std::shared_ptr<Ray> reflectRay = std::make_shared<Ray>();

	//	reflectRay->mOrigin = _intersection + reflectRay->mDirection * 0.001f;
	//	reflectRay->mDirection = glm::reflect(-_ray->mDirection, normal);

	//	reflectColour = 0.5f * _rayTracer.TraceRay(reflectRay, _count - 1);
	//}


	//colour = (diffuseColour + specularColour + ambient) * lightColour * mColour +reflectColour * mColour;

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