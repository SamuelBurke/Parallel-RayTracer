#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>

//Ray Class
//Ray-object intersection routines.
class Ray
{
public:
	glm::vec3 m_origin;
	glm::vec3 m_direction; // normalised.
};

#endif // !RAY_H
