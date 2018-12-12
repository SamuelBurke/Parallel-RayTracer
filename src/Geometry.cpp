#include "Geometry.h"
#include "Ray.h"
#include "Sphere.h"

#include <iostream>
#include <cmath>

Geometry::Geometry()
{
}

bool Geometry::Intersect(std::shared_ptr<Ray> _ray, float &_t, glm::vec3 _sphereCentre, float _radius)
{
	glm::vec3 originToCentre = _ray->mOrigin - _sphereCentre;
	float b = 2 * glm::dot(originToCentre, _ray->mDirection);
	float c = glm::dot(originToCentre, originToCentre) - _radius * _radius;

	float distanceToCentre = b * b - 4 * c;
	if (distanceToCentre < 1e-4)
	{
		return false;
	}

	distanceToCentre = sqrt(distanceToCentre);

	float t0 = -b - distanceToCentre;
	float t1 = -b + distanceToCentre;

	_t = (t0 < t1) ? t0 : t1;
	return true;
}


// Need three functions:
glm::vec3 Geometry::ClosestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query)
{
	glm::vec3 point = _query;

	// Function to get the closest point on a line.
	// Takes a ray, a 3D query point, returns a 3D point.
	// Can express the closest point (X) on the line to a query point (P) as:
	// X = a+((P-a).n)n
	// The vector from X to P is:
	// P - X
	// Can take the radius(R) of the sphere.
	//
	// If ||P - X|| <= R  --- The || means the length, magnitude or norm of a vector.
	//		Ray intersects with the sphere.
	// Else
	//		Ray does not intersect with the sphere.
	
	//(P - a).n
	// Where:
	//	a = Origin of ray
	//	n = Direction of ray, unit vector
	//	P = position vector. In this case, it's of the query point passed in here.
	// This gives us the length along the line to the closest point
	float projectedVector = glm::dot((point - _ray->mOrigin), _ray->mDirection);

	// projectedVector gives us a scalar value. If we want a vector to the closest point, it is this distance along the n.
	// So, just multiply it by n
	//result = projectedVector * rayDirection;

	// This means we can now express the closest point X on the line to our query point P as:
	glm::vec3 X = _ray->mOrigin + (projectedVector * _ray->mDirection);
	

	// We can also easily find the vector from X on the line to the point described by P.
	// P - a - ((P - a).n)n 
	// The shortest distance d is thereform the magnitude of this vector:
	// d = ||P - a - ((P - a).n)n||
	//float d = glm::length(point - _ray->m_origin - (projectedVector * _ray->m_direction));

	return X;
}


// Function to calculate Ray-sphere intersection.
// Takes a ray, sphere centre, and radius. Returns whether it hit or not, and distance to hit.
// (use a stucture or class to combine these potentially)
// Ray-Sphere needs to:
// First, check if ray origin is inside the sphere.
// (if it is, treat as an error and say there is not intersection).
// Then, find the closest point on the ray to the centre of the sphere. (Use function above).
// Check if the closest point is in front of or behind the ray's origin/direction.
// (reject if intersection is behind the ray's origin and direction points away from it).
// (prevents drawing objects that are behind the camera).
// Work out the distance from the closest point on the line to the sphere's centre.
// Perform the three checks.
// (work out and return actual intersection points).

//bool Geometry::RaySphereIntersection(std::shared_ptr<Ray> _ray, glm::vec3 _sphereCentre, float _radius)
//{
// 	//Check if ray origin is inside the sphere. //////////DOES NOT WORK/////////////
//	glm::vec3 outerSphere = _sphereCentre + _radius;
//	glm::vec3 innerSphere = _sphereCentre - _radius;
//
//	if (_ray->m_origin.x > outerSphere.x && _ray->m_origin.x < innerSphere.x ||
//		_ray->m_origin.y > outerSphere.y && _ray->m_origin.y < innerSphere.y ||
//		_ray->m_origin.z > outerSphere.z && _ray->m_origin.z < innerSphere.z)
//	{
//		return false;
//	}
//
//	glm::vec3 X = ClosestPoint(_ray, _sphereCentre);
//
//	// CHECK IF CLOSESTPOINT IS BEHIND THE RAY'S ORIGIN/DIRECTION
//	// REJECT IF INTERSECTION IS BEHIND THE RAY'S ORIGIN AND THE DIRECTION POINTS AWAY FROM IT.
//
//	// No intersection points.
//	if (glm::length(_sphereCentre - X) > _radius)
//	{
//		return false;
//	}
//
//	// One intersection point.
//	if (glm::length(_sphereCentre - X) == _radius)
//	{
//		return true;
//	}
//
//	// Two intersection points.
//	if (glm::length(_sphereCentre - X) < _radius)
//	{
//		return true;
//	}
//
//	
//
//
//
//}

// Function to get the normal of a sphere
// Takes a sphere centre and a 3D sample point. Returns a 3D direction vector.
// For lighting calculations, we will need the surface normal.
// The intersection point is at the surface of the sphere.
// Generate surface normal at the intersection point.

// Basic diffuse light equation:
// L = (Wi . N)Li Kd
// Need a surface normal(N) and a vector pointing toward the light source(Wi)
// Simplest treatment of Wi is to set it as a constant value
// Could call this a 'distant' light, all the light rays are parallel.
// (makes sure the result of the dot project is always >= 0).