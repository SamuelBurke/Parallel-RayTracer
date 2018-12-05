#include "Sphere.h"

Sphere::Sphere()
{
	//m_radius = 50.0f;
	//m_position = glm::vec3(0, 0, -10.0f);
	//m_colour = glm::vec3(255, 0, 0);
}

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, glm::vec3(_intersection))
{
	// This function takes a ray and a vec3 intersection point.
	// Returns a colour.
	// Set this function to return a specific value, e.g. red.
	// Handled colours as between 0-1 in the function and convert to between 0-255 as need when writing the final pixel colour to screen.
	// Will make the maths a lot easier when proper shading.
	// Will change this function to eventually perform actual shading.

	glm::vec3 colour = glm::vec3(0, 0, 0);

	return colour;
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