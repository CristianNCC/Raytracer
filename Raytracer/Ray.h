#pragma once

#include <glm/vec3.hpp>

class cRay
{
public:

	cRay(const glm::vec3& origin, const glm::vec3& direction) :
		m_origin(origin), m_direction(direction) 
	{

	}

	glm::vec3 GetOrigin();
	glm::vec3 GetDirection();

	glm::vec3 GetPointAt(float t);

private:
	glm::vec3 m_origin;
	glm::vec3 m_direction;
};

