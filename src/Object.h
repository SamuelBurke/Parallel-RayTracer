#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <memory>

class Ray;
class RayTracer;

//! Base class for the objects. Handles object properties, and contains virtual functions with the intentions of being overrided.
class Object 
{
public:
	Object();

	// Set functions update the protected variables of this class. Called from the application's initialise class.
	void SetPosition(glm::vec3 _position);
	void SetColour(glm::vec3 _colour);
	void SetRadius(float _radius);

	// virtual functions will be overrided by the functions in the child classes.
	virtual glm::vec3 GetNormal(glm::vec3 _pi);
	virtual glm::vec3 Shade(std::shared_ptr<Ray> _ray, RayTracer& _rayTracer, glm::vec3(_intersection), int _count);

	// Get functions return the protected variables of this class.
	glm::vec3 GetPosition();
	glm::vec3 GetColour();
	float GetRadius();

protected:
	glm::vec3 mPosition; 
	float mRadius;
	glm::vec3 mColour;
};

#endif // !OBJECT_H
