#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>
#include <memory>
#include <vector>


class Sphere;
class Ray;
class Geometry;

// Keeps track of all objects in the scene.
// Routine 'trace ray' test ray against all objects in scene, returns pixel colour.
class RayTracer
{
public:
	RayTracer();

	glm::vec3 TraceRay(std::shared_ptr<Ray> _ray, int _count);

	void AddObject(std::shared_ptr<Sphere> _object);

private:
	std::vector<std::shared_ptr<Sphere>> mObjects;

	std::shared_ptr<Geometry> mGeometry;

	float mBlue;
};

#endif // !RAYTRACER_H
