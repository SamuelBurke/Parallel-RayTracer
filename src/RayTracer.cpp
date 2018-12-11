#include "RayTracer.h"
//#include "Object.h"
#include "Sphere.h"
#include "Geometry.h"
#include "Ray.h"

#include <iostream>

RayTracer::RayTracer()
{
	m_blue = 0.109375f;

	m_geometry = std::make_shared<Geometry>();

	m_primaryRay = 0;

	
}

// Will test the incoming ray against all objects in the scene.
glm::vec3 RayTracer::TraceRay(std::shared_ptr<Ray> _ray)
{
	glm::vec3 colour = glm::vec3(0, 0, 0);
	float t;


	// Find the first object the ray hits.
	// Go through every object in the scene:
	// Call the ray-sphere intersection function.
	// If it hits the objects, record the distance from the ray's origin to the intersection point.
	// Want the object with the shortest distance.

	for (size_t i = 0; i < m_objects.size(); i++)
	{
		if (m_geometry->Intersect(_ray, t, m_objects.at(i)->GetPosition(), m_objects.at(i)->GetRadius()))
		{
			glm::vec3 pi = _ray->m_origin + _ray->m_direction * t;
			colour = m_objects.at(i)->Shade(_ray, pi);

				
			//if (m_primaryRay > 1)
			//{
			//	//std::shared_ptr<Ray> reflectRay = std::make_shared<Ray>();
			//	_ray->m_origin = pi;
			//	_ray->m_direction = glm::reflect(_ray->m_direction, normal);

			//	m_primaryRay++;

			//	colour += TraceRay(_ray);

			//	//std::shared_ptr<Ray> shadowRay = std::make_shared<Ray>();
			//	_ray->m_origin = pi;
			//	_ray->m_direction = lightDirection;
			//	colour += TraceRay(_ray);

			//}

			break;
		}
		else
		{
			glm::vec3 bkgcolour = glm::vec3(0, 0, m_blue);
			colour = bkgcolour;

		}
	}

	// If the ray hits an object:
	// Call that object's shading method.
	// Return the pixel colour.

	// If the ray didn't hit an object:
	// Just return a background colour, as done below:

	return colour;
}

void RayTracer::ClampColour(glm::vec3 &_col)
{
	_col.x = (_col.x > 1) ? 1 : (_col.x < 0) ? 0 : _col.x;
	_col.y = (_col.y > 1) ? 1 : (_col.y < 0) ? 0 : _col.y;
	_col.z = (_col.z > 1) ? 1 : (_col.z < 0) ? 0 : _col.z;
}

void RayTracer::AddObject(std::shared_ptr<Sphere> _object)
{
	m_objects.push_back(_object);
}

void RayTracer::Debug()
{
	//std::cout << m_objects.size() << std::endl;
}