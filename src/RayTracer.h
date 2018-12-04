#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>
#include <memory>
#include <vector>

class Object;
class Ray;
// Keeps track of all objects in the scene.
// Routine 'trace ray' test ray against all objects in scene, returns pixel colour.
class RayTracer
{
public:
	RayTracer();

	glm::vec3 TraceRay(std::shared_ptr<Ray> _ray);

	void AddObject(std::shared_ptr<Object> _object);

private:
	std::vector<std::shared_ptr<Object>> m_objects;
};

#endif // !RAYTRACER_H
