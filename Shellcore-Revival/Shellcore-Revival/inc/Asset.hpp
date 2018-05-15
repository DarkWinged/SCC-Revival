#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace SCC_R {
	namespace Graphics {
		class Asset
		{
		public:
			Asset();
			~Asset();
			GLuint image;
		};

	}
}