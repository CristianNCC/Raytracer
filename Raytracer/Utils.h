#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "glm/vec3.hpp"

class cOutputRedirect final
{
public:

    cOutputRedirect(const std::string& filename);
    ~cOutputRedirect();

    void PrintInPreviousStream(const std::string& message) const;

protected:

    cOutputRedirect(cOutputRedirect& other) = delete;
    cOutputRedirect& operator=(cOutputRedirect& other) = delete;

    cOutputRedirect(cOutputRedirect&& other) = delete;
    cOutputRedirect& operator=(cOutputRedirect&& other) = delete;

private:
    std::ofstream   m_outputStream;
    std::streambuf* m_previousStreamBuffer = nullptr;
};

class cUtils final
{
public:
    static void WriteColorToOut(const glm::vec3& color);
};