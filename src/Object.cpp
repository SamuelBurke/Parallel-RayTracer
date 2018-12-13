#include "Object.h"

Object::Object()
{
	
}

glm::vec3 Object::GetNormal(glm::vec3 _pi)
{
	return glm::vec3(0);
}

glm::vec3 Object::Shade(std::shared_ptr<Ray> _ray, RayTracer& _rayTracer, glm::vec3(_intersection), int _count)
{
	return glm::vec3(0);
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