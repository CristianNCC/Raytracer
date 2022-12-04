#pragma once

#include <string>

class cRenderer final
{
public:

	void WriteImage() const;
	
	static const std::string& GetOutputImage();

private:
	static const std::string m_outputImage;
};

