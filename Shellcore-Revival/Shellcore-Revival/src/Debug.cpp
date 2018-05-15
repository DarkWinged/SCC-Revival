#include <Debug.hpp>



namespace SCC_R {
	
	void Debug::GLClearError()
	{
		while (glGetError() != GL_NO_ERROR)
		{

		}
	}

	bool Debug::GLLogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			std::cout << "[Opengl Error] (" << error << "): " << function <<
				" " << file << ":" << line << std::endl;
			return false;
		}
		return true;
	}
}