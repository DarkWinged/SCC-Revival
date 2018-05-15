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

			window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "SCC_R", NULL, NULL);
			if (window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(window);
			//GUI::framebuffer_size_callback(window, SCR_WIDTH, SCR_HEIGHT);
			//glfwSetFramebufferSizeCallback(window,);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to initialize glew" << std::endl;
				return false;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;
			return true;
		}

		int GUI::loop()
		{
			float verticies[8] = {
				-0.5f, -0.5f,
				0.5f, -0.5f,
				0.5f,  0.5f
				-0.5f,  0.5f
			};
			
			unsigned int indices[]
			{
				0, 1, 2,
				2, 3 ,0
			};

			unsigned int vbId;
			GLDebug(glGenBuffers(1,&vbId));
			GLDebug(glBindBuffer(GL_ARRAY_BUFFER, vbId));
			GLDebug(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), verticies, GL_STATIC_DRAW));

			GLDebug(glEnableVertexAttribArray(0));
			GLDebug(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float),0));

			unsigned int ibId;
			GLDebug(glGenBuffers(1, &ibId));
			GLDebug(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibId));
			GLDebug(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

			ShaserProgramSource source = shaderManager.ParseShader("assets/shaders/test.shader");
			unsigned int shader = shaderManager.CreateShaderProgram(source.VertexSource, source.FragmentSource);
			glUseProgram(shader);
			
			while (!glfwWindowShouldClose(window))
			{
				processInput();

				GLDebug(glClearColor(0.2f, 0.2f, 0.2f, 0.0f));
				GLDebug(glClear(GL_COLOR_BUFFER_BIT));

				GLDebug(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
				
				GLDebug(glfwSwapBuffers(window));
				GLDebug(glfwPollEvents());
			}

			GLDebug(glDeleteProgram(shader));
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
		void GUI::framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			// make sure the viewport matches the new window dimensions; note that width and 
			// height will be significantly larger than specified on retina displays.
			glViewport(0, 0, width, height);
		}
	}
}