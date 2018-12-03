#include "Camera.h"

std::shared_ptr<Ray> Camera::GenerateRay(glm::ivec2 _pos)
{
	std::shared_ptr<Ray> ray = std::make_shared<Ray>();

	ray->m_orientation.x = _pos.x;
	ray->m_orientation.y = _pos.y; 	

	// Needs a viewing matrix - Represent the camera's position and orientation.
	// Needs a projection matrix - Act like the camera's lens.

	// Must go through a number of steps to create a ray from the input pixel coordinates.
	// Step 1:
	// Normalised Device Coordinates: Viewing volume is a cube, from -1 to +1 in each dimension.
	// NDC space is left-handed (a projection matrix converts from right to left-handed).
	// Need to generate coordinates for the start and end points of the ray.
	// These go from the near plane (z = -1) to the far plane (z = 1).
	// E.G. Pixel coords (0, 0) map to NDC (-1, 1, -1) on near plane. Pixel coords (0, 0) map to NDC (-1, 1, 1) on far plane.
	// Step 2:
	// Convert to Eye Space:
	// Multiply coordinates by inverse projection matrix. - This is like distorting the cube into the correct perspective volume.
	// Step 3:
	// Convert from Left-Handed to Right-Handed coordinate system.
	// Multiplying by projection matrix gives non-zero w values.
	// Need to divide coordinates by w.
	// Step 4:
	// Convert from Eye Space to World Space.
	// Takes into account the camera's position in the world.
	// Need to multiply coordinates by inverse view matrix.

	// Should then have two coordinates in world space.
	// Use these to define the ray that will get returned.

	return ray;
}