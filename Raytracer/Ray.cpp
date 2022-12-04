#include "Ray.h"

glm::vec3 cRay::GetOrigin()
{
	return m_origin;
}

glm::vec3 cRay::GetDirection()
{
	return m_direction;
}

glm::vec3 cRay::GetPointAt(float t)
{
	return m_origin + (m_direction * t);
}
