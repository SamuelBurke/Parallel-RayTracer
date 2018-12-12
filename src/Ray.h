#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>

//Ray Class
//Ray-object intersection routines.
class Ray
{
public:
	glm::vec3 mOrigin;
	glm::vec3 mDirection; // normalised.
};

#endif // !RAY_H
