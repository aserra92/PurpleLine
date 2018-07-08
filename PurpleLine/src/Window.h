#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace PurpleLine{ namespace Graphics {
	
	class Window
	{
	public:
		Window();
		~Window();

		bool Initialize();
		bool IsClosed();
		void PollEventsAndSwapBuffers();
		void Clear();
	private:
		GLFWwindow *window;
	};
}
}
