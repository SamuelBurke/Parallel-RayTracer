#include "RayTracer.h"
//#include "Object.h"
#include "Sphere.h"
#include "Geometry.h"
#include "Ray.h"

#include <iostream>

RayTracer::RayTracer()
{
	mBlue = 0.109375f; // Since the colours are from 0-1, this value is 28/255. 28 is the value of a preferred background shade of blue.
	mGeometry = std::make_shared<Geometry>();
}

glm::vec3 RayTracer::TraceRay(std::shared_ptr<Ray> _ray, int _count)
{
	glm::vec3 colour = glm::vec3(0, 0, 0);
	float t;

	for (size_t i = 0; i < mObjects.size(); i++) // Iterate through each object.
	{
		if (mGeometry->RaySphereIntersect(_ray, t, mObjects.at(i)->GetPosition(), mObjects.at(i)->GetRadius())) // Check if the ray intersects with the sphere.
		{
			// t is the distance from the closest point of the ray to the radius of the sphere. The value gets returned from the function called above.
			glm::vec3 pointOfIntersection = _ray->mOrigin + _ray->mDirection * t; // Calculate the point of intersection using the ray's values and the t value.
			colour = mObjects.at(i)->Shade(_ray, *this, pointOfIntersection, _count); // Set the colour of the ray by calling the shade function and passing the point of intersection into it.

			break; // Break out of the for loop for this particular ray.
		}
		else
		{
			glm::vec3 bkgcolour = glm::vec3(0, 0, mBlue); // Used the blue background shade defined in the constructor.
			colour = bkgcolour;

		}
	}

	return colour;
}


void RayTracer::AddObject(std::shared_ptr<Object> _object)
{
	mObjects.push_back(_object);
}