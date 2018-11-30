#include "Camera.h"

std::shared_ptr<Ray> Camera::GenerateRay(glm::ivec2 _pos)
{
	std::shared_ptr<Ray> ray = std::make_shared<Ray>();

	ray->m_orientation.x = _pos.x;
	ray->m_orientation.y = _pos.y; 	

	return ray;
}