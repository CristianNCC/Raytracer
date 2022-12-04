#include "Renderer.h"
#include "Utils.h"

#include <format>

const std::string cRenderer::m_outputImage = "image.ppm";

void cRenderer::WriteImage() const
{
    cOutputRedirect coutRedirectToFile(m_outputImage);

    const int imageWidth = 256;
    const int imageHeight = 256;

    std::cout << "P3" << std::endl
        << imageWidth << ' ' << imageHeight << std::endl
        << 255 << std::endl;

    for (int j = imageHeight - 1; j >= 0; --j)
    {
        coutRedirectToFile.PrintInPreviousStream(std::format("Scanlines remaining: {}.", j));
        for (int i = 0; i < imageWidth; ++i)
        {
            auto r = float(i) / (imageWidth - 1);
            auto g = float(j) / (imageHeight - 1);
            auto b = 0.25;

            int ir = static_cast<int>(256.f * r);
            int ig = static_cast<int>(256.f * g);
            int ib = static_cast<int>(256.f * b);

            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }
}

const std::string& cRenderer::GetOutputImage()
{
    return m_outputImage;
}
