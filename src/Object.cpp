#include "Object.h"

Object::Object()
{
	
}

glm::vec3 Object::GetNormal(glm::vec3 _pi)
{
	return glm::vec3(0); // Just to keep the compiler happy. This function will be overrided by the child classes(Sphere).
}

glm::vec3 Object::Shade(std::shared_ptr<Ray> _ray, RayTracer& _rayTracer, glm::vec3(_intersection), int _count)
{
	return glm::vec3(0); // Same as above, always overrided.
}

void Object::SetPosition(glm::vec3 _position)
{
	mPosition = _position;
}

void Object::SetColour(glm::vec3 _colour)
{
	mColour = _colour;
}

void Object::SetRadius(float _radius)
{
	mRadius = _radius;
}

glm::vec3 Object::GetPosition()
{
	return mPosition;
}

glm::vec3 Object::GetColour()
{
	return mColour;
}

float Object::GetRadius()
{
	return mRadius;
}