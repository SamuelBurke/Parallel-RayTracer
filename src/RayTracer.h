#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>
#include <memory>

class Ray;
// Keeps track of all objects in the scene.
// Routine 'trace ray' test ray against all objects in scene, returns pixel colour.
class RayTracer
{
public:
	RayTracer();

	glm::vec3 TraceRay(std::shared_ptr<Ray> _ray);
};

#endif // !RAYTRACER_H
