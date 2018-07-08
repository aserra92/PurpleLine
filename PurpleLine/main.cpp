#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "src/Graphics/Window.h"
#include "src/Graphics/Shader.h"
#include "src/Graphics/Buffers/ArrayBuffer.h"
#include "src/Graphics/Buffers/VertexArray.h"
#include "src/Graphics/Renderable/StaticSprite.h"
#include "src/Maths/maths.h"

int Close()
{
	system("PAUSE");
	return 0;
}

int main(int argc, char *argv[])
{
	using namespace PurpleLine;
	using namespace Graphics;
	Window *window = new Window();
	if (!window->Initialize())
	{
		return Close();
	}
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	VertexArray *vertexArray = new VertexArray();
	GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	ArrayBuffer *arrayBuffer = new ArrayBuffer(g_vertex_buffer_data, 3 * 3, 3);
	vertexArray->AddBuffer(arrayBuffer, 0);
	
	Shader *shader = new Shader("E:\\OneDrive\\els meus documents\\Aria\\jocs\\PurpleLine\\Shaders\\basic.vs", "E:\\OneDrive\\els meus documents\\Aria\\jocs\\PurpleLine\\Shaders\\basic.frag");
	if (!shader->Compiled())
	{
		return Close();
	}
	shader->Enable();
	shader->SetUniform4f("color", Math::Vector4(0, 0, 1, 1));
	StaticSprite* staticSprite = new StaticSprite(Math::Vector4(0, 0, 1, 1), *shader);
	staticSprite->SetColor(Math::Vector4(0, 0, 1, 1));

	while (!(window->IsClosed()))
	{
		window->Clear();
		shader->Enable();

		// 1st attribute buffer : vertices
		glEnableVertexAttribArray(0);
		arrayBuffer->Bind();
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);

		window->PollEventsAndSwapBuffers();
	}	
	return 0;
}