#include "Renderer.h"

int32_t main()
{
    cRenderer renderer;
    renderer.WriteImage();

    system(cRenderer::GetOutputImagePath().c_str());
    return 0;
}