#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GUI.hpp>

#include <iostream>

// settings

int main()
{
	using namespace SCC_R::Control;
	GUI gui;
	if (!gui.init())
		return 1;
	gui.loop();
	return 0;
}

