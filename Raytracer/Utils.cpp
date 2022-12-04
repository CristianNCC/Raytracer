#include "Utils.h"

cOutputRedirect::cOutputRedirect(const std::string& filename)
{
    m_outputStream.open(filename, std::ofstream::out | std::ofstream::trunc);
    if (m_outputStream.good())
    {
        m_previousStreamBuffer = std::cout.rdbuf();
        std::cout.rdbuf(m_outputStream.rdbuf());
    }
}

cOutputRedirect::~cOutputRedirect()
{
    if (m_previousStreamBuffer)
    {
        std::cout.rdbuf(m_previousStreamBuffer);
    }
}

void cOutputRedirect::PrintInPreviousStream(const std::string& message) const
{
    std::cout.rdbuf(m_previousStreamBuffer);
    std::cout << message << std::endl;
    std::cout.rdbuf(m_outputStream.rdbuf());
}

void cUtils::WriteColorToOut(const glm::vec3& color)
{
    std::cout << static_cast<int32_t>(256.f * color.r) << ' '
              << static_cast<int32_t>(256.f * color.g) << ' '
              << static_cast<int32_t>(256.f * color.b) << std::endl;
}
