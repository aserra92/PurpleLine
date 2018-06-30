#include "Window.h"

#include <iostream>

namespace PurpleLine{ namespace Graphics {

Window::Window()
{
}


Window::~Window()
{
	glfwTerminate();
}

bool Window::Initialize()
{
	if (!glfwInit())
	{
		std::cout << "Library GLFW cannot be initialized" << std::endl; //TODO: do with log
		return false;
	}

	window = glfwCreateWindow(1280, 720, "PurpleLine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "GLFW Window cannot be created" << std::endl; //TODO: do with log
		return false;
	}
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW failed to initialize" << std::endl; //TODO: do with log
		return false;
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl; //TODO: do with log
	return true;
}

bool Window::IsClosed()
{
	if (window != nullptr)
	{
		return glfwWindowShouldClose(window);
	}
	return true;
}

void Window::PollEventsAndSwapBuffers()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

}}