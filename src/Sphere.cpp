#include "Sphere.h"
#include "Ray.h"
#include "RayTracer.h"

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, RayTracer& _rayTracer, glm::vec3(_intersection), int _count)
{
	glm::vec3 colour = glm::vec3(0, 0, 0); // Initialise the colour variable.
	glm::vec3 lightOrigin = glm::vec3(320.0f, 280.0f, 100.0f); // This is the coordinates of the light source.
	glm::vec3 lightColour = glm::vec3(1.0f);

	glm::vec3 lightDirection = lightOrigin - _intersection; // Calculate the direction of the light in relation to the intersection point hit.
	glm::vec3 normal = GetNormal(_intersection); 

	float shade = glm::dot(glm::normalize(lightDirection), glm::normalize(normal)); // Calculates the dot product of the normalised light direction and the normal.

	glm::vec3 reflectColour = glm::vec3(0); // Initalise the colour of the reflection.
	if (_count > 0) // Count is associated with the amount of times the ray 'bounces' off the surfaces in the scene. Currently set to 2.
	{
		std::shared_ptr<Ray> reflectRay = std::make_shared<Ray>(); // Create a new ray for the reflections.

		reflectRay->mOrigin = _intersection + reflectRay->mDirection * 0.0001f; // Sets the reflection ray's origin to intersection point, multiply by a slight offset to avoid reflecting with self.
		reflectRay->mDirection = glm::reflect(-_ray->mDirection, normal); // Set the reflection ray's direction the glm::reflect result of the inital ray's direction and the normal of the sphere.

		reflectColour = 0.5f * _rayTracer.TraceRay(reflectRay, _count - 1); // Pass this new ray in the trace ray function, this will return the colour of the reflection. Half the value to reduce intensity.
	}

	colour = ((mColour + lightColour * shade) * 0.55f) + reflectColour * mColour; // Multiply the colours of the sphere, light and shade to get the shading working correctly.
																				  // The 0.55 float is a value to reduce the intensity of the returned colour, since multiple colours and being multiplied together.
																				  // Then add the reflection colour to the result, and multiply the sphere's colour to that reflection.

	return glm::clamp(colour, glm::vec3(0), glm::vec3(1)); // Since we're multiplying colour values with each other, this stops the values inverting by going above 1 or below 0.
}

glm::vec3 Sphere::GetNormal(glm::vec3 _intersection)
{
	return (_intersection - mPosition) / mRadius; // Returns the normal of the sphere. Minus the intersection point from the sphere's centre point, then divide the result by the radius.
}