#include "Utils.h"
#include "Utils.h"
#include "Renderer.h"

int main() 
{
    cRenderer renderer;

    std::cout << "Raytracer start..." << std::endl;
    renderer.WriteImage();
    std::cout << "Raytracer stop..." << std::endl;

    system(cRenderer::GetOutputImage().c_str());
}