#include "Renderer.h"
#include "Utils.h"

#include <format>

const std::string cRenderer::m_outputImage = "image.ppm";

void cRenderer::WriteImage() const
{
    cOutputRedirect coutRedirectToFile(m_outputImage);

    std::cout << "P3" << std::endl
        << m_imageWidth << ' ' << m_imageHeight << std::endl
        << 255 << std::endl;

    for (int32_t j = m_imageHeight - 1; j >= 0; --j)
    {
        coutRedirectToFile.PrintInPreviousStream(std::format("Scanlines remaining: {}.", j));
        for (int32_t i = 0; i < m_imageWidth; ++i)
        {
            float r = static_cast<float>(i) / (m_imageWidth - 1);
            float g = static_cast<float>(j) / (m_imageHeight - 1);
            float b = 0.25f;

            cUtils::WriteColorToOut(glm::vec3(r, g, b));
        }
    }
}

const std::string& cRenderer::GetOutputImagePath()
{
    return m_outputImage;
}
