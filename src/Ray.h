#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>

//! Simply has two public variables. The origin and the direction of the ray.
class Ray
{
public:
	glm::vec3 mOrigin;
	glm::vec3 mDirection;
};

#endif // !RAY_H
