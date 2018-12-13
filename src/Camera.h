#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"

#include <memory>
#include <glm/glm.hpp>

//! Has viewing properties - Used to generate the rays.
class Camera
{
public:
	Camera();

	// Called in application for each ray. Sets the ray's origin & direction.
	std::shared_ptr<Ray> GenerateRay(glm::ivec2 _pos);

private:
	//glm::mat4 mViewMatrix; // Represents the camera's position and orientation.
	//glm::mat4 mProjectionMatrix; // To act like the camera's lens.

	//glm::vec4 mNearPlane;
	//glm::vec4 mFarPlane;


};

#endif // !CAMERA_H
