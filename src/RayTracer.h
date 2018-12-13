#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>
#include <memory>
#include <vector>

class Object;
class Ray;
class Geometry;

//! Has knowledge of each object. Intersection functions get called within this class.
class RayTracer
{
public:
	RayTracer();

	// Tests all rays against the objects, and returns a pixel colour.
	glm::vec3 TraceRay(std::shared_ptr<Ray> _ray, int _count);

	void AddObject(std::shared_ptr<Object> _object);

private:
	std::vector<std::shared_ptr<Object>> mObjects;
	std::shared_ptr<Geometry> mGeometry;

	float mBlue; // Background colour.
};

#endif // !RAYTRACER_H
