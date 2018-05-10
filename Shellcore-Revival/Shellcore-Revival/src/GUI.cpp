#include <GUI.hpp>


namespace SCC_R {
	namespace Control {

		GUI::GUI()
		{
		}


		GUI::~GUI()
		{
		}

		bool GUI::init()
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

													 // glfw window creation
													 // --------------------
			window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
			if (window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
				return false;
			}
			glfwMakeContextCurrent(window);
			//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

			// glad: load all OpenGL function pointers
			// ---------------------------------------
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to initialize glew" << std::endl;
				return false;
			}

			return true;
		}

		int GUI::loop()
		{
			while (!glfwWindowShouldClose(window))
			{
				// input
				// -----
				processInput();

				// render
				// ------
				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);

				// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
				// -------------------------------------------------------------------------------
				glfwSwapBuffers(window);
				glfwPollEvents();
			}

			// glfw: terminate, clearing all previously allocated GLFW resources.
			// ------------------------------------------------------------------
			glfwTerminate();
			return 0;
		}


		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
		// ---------------------------------------------------------------------------------------------------------
		void GUI::processInput()
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		}

		// glfw: whenever the window size changed (by OS or user resize) this callback function executes
		// ---------------------------------------------------------------------------------------------
		void GUI::framebuffer_size_callback(int width, int height)
		{
			// make sure the viewport matches the new window dimensions; note that width and 
			// height will be significantly larger than specified on retina displays.
			glViewport(0, 0, width, height);
		}
	}
}