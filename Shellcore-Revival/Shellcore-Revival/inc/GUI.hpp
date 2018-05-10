#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace SCC_R {
	namespace Control {

		class GUI
		{
		public:
			GUI();
			~GUI();
			bool init();
			int loop();

			void framebuffer_size_callback(int width, int height);
			void processInput();

			const unsigned int SCR_WIDTH = 960;
			const unsigned int SCR_HEIGHT = 540;
			GLFWwindow* window;
		};
	}
}