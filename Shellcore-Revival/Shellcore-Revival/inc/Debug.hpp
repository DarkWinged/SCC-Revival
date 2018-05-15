#pragma once

#include <GL/glew.h>

#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLDebug(x) Debug::GLClearError();\
	x;\
	ASSERT(Debug::GLLogCall(#x, __FILE__, __LINE__))

namespace SCC_R {
	class Debug
	{
	public:
		static void GLClearError();
		static bool GLLogCall(const char* function, const char* file, int line);
	};
}