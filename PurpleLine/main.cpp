#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "src/Graphics/Window.h"
#include "src/Graphics/Shader.h"
#include "src/Graphics/Buffers/ArrayBuffer.h"
#include "src/Graphics/Buffers/VertexArray.h"
#include "src/Graphics/Renderable/StaticSprite.h"
#include "src/Maths/maths.h"
#include "src/Graphics/SimpleRenderer2D.h"

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
	
	Shader *shader = new Shader("E:\\OneDrive\\els meus documents\\Aria\\jocs\\PurpleLine\\Shaders\\basic.vs", "E:\\OneDrive\\els meus documents\\Aria\\jocs\\PurpleLine\\Shaders\\basic.frag");
	if (!shader->Compiled())
	{
		return Close();
	}
	shader->Enable();
	StaticSprite* staticSprite = new StaticSprite(2.5f, 2.5f, Math::Vector4(0, 0, 1, 1), *shader);
	staticSprite->SetColor(Math::Vector4(0, 0, 1, 1));

	SimpleRenderer2D* renderer = new SimpleRenderer2D();

	while (!(window->IsClosed()))
	{
		window->Clear();
		shader->Enable();
		renderer->Submit(staticSprite);
		renderer->Flush();
		window->PollEventsAndSwapBuffers();
	}	
	return 0;
}