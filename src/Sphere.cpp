#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere()
{
}

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, glm::vec3(_intersection))
{
	glm::vec3 colour = glm::vec3(0, 0, 0);
	//float specularIntensity = 1.0f;
	//float ambientStength = 0.1f;

	//ambient
	//glm::vec3 ambient = ambientStength * m_colour;
	glm::vec3 lightDirection = glm::vec3(0.0f, 0.0f, 0.0f) - _intersection; // The vector here is the light's origin point. -pi in order to get the direction of the light.
	glm::vec3 normal = GetNormal(_intersection);

	//diffuse
	float dt = glm::dot(glm::normalize(lightDirection), glm::normalize(normal));
	//float diffuseColour = glm::max(dt, 0.0f);

	//specular
	//glm::vec3 reflect = glm::reflect(-lightDirection, normal);
	//glm::vec3 camView = glm::normalize(-_ray->m_direction);
	//float specularColour = glm::pow(glm::max(glm::dot(camView, glm::normalize(reflect)), 0.0f), 50);
	//specularColour *= specularIntensity;

	//colour = (diffuseColour + specularColour + ambient) * glm::vec3(1.0f) * m_colour;

	colour = (m_colour + glm::vec3(1.0f) * dt) * 0.5f;

	return glm::clamp(colour, glm::vec3(0), glm::vec3(1));
}

glm::vec3 Sphere::GetNormal(glm::vec3 _pi)
{
	return (_pi - m_position) / m_radius;
}

void Sphere::SetPosition(glm::vec3 _position)
{
	m_position = _position;
}

void Sphere::SetRadius(float _radius)
{
	m_radius = _radius;
}

void Sphere::SetColour(glm::vec3 _colour)
{
	m_colour = _colour;
}

glm::vec3 Sphere::GetPosition()
{
	return m_position;
}

float Sphere::GetRadius()
{
	return m_radius;
}

glm::vec3 Sphere::GetColour()
{
	return m_colour;
}