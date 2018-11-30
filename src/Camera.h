#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"

#include <memory>
#include <glm/glm.hpp>

// Has viewing properties.
// Routine to generate a ray.
class Camera
{
public:
	std::shared_ptr<Ray> GenerateRay(glm::ivec2 _pos);


};

#endif // !CAMERA_H
