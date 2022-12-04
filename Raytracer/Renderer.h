#pragma once

#include <string>

class cRenderer final
{
public:

	void WriteImage() const;
	
	static const std::string& GetOutputImagePath();

private:
	static const std::string m_outputImage;

	const int32_t m_imageWidth = 256;
	const int32_t m_imageHeight = 256;
};

