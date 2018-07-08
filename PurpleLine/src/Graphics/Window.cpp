#include "Window.h"
#include "../Utils/Log.h"

namespace PurpleLine{ namespace Graphics {

using namespace Internal;

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
		LOG_FATAL("Library GLFW cannot be initialized");
		return false;
	}

	window = glfwCreateWindow(1280, 720, "PurpleLine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		LOG_FATAL("GLFW Window cannot be created");
		return false;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);

	if (glewInit() != GLEW_OK)
	{
		LOG_FATAL("GLEW failed to initialize");
		return false;
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	LOG_INFO("OpenGL ", glGetString(GL_VERSION));
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
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		LOG_ERROR("openGL error!!: ", error);
	}
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

}}