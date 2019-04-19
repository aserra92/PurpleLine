#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "src/Graphics/Window.h"
#include "src/Graphics/Shader.h"
#include "src/Graphics/Renderable/StaticSprite.h"
#include "src/Maths/maths.h"
#include "src/Graphics/SimpleRenderer2D.h"
#include "src/Utils/Timer.h"
#include "src/Utils/Log.h"
#include "src/Scene/Scene2D.h"

int Close()
{
	system("PAUSE");
	return 0;
}

int main(int argc, char *argv[])
{
	using namespace PurpleLine;
	using namespace Graphics;
	using namespace GameObjects;
	Window *window = new Window();
	if (!window->Initialize())
	{
		return Close();
	}
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	Scene2D *scene = new Scene2D("Escena 1");
	GameObject* rectangle = new GameObject("Rectangle 1");
	scene->AddGameObject(rectangle);
	rectangle->GetTransform()->SetPosition(Math::Vector3(-1, -1, 0));
	
	Shader *shader = new Shader("E:\\OneDrive\\els meus documents\\Aria\\jocs\\PurpleLine\\Shaders\\basic.vs", "E:\\OneDrive\\els meus documents\\Aria\\jocs\\PurpleLine\\Shaders\\basic.frag");
	if (!shader->Compiled())
	{
		return Close();
	}
	shader->Enable();
	Sprite* sprite = new Sprite(Math::Vector3(0, 0, 0), Math::Vector2(0.05f, 0.05f), 0x0000000);
	sprite->SetColor(Math::Vector4(1, 1, 0, 1));
	rectangle->AddComponent(new SpriteComponent(rectangle, sprite));
	sprite->SetTransform(rectangle->GetTransform());
#if 0
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			GameObject* clone = rectangle->Clone();
			clone->GetTransform()->SetPosition(Math::Vector3(i, j, 0));
			((SpriteComponent*)clone->GetComponent(ComponentType::SpriteComponentType))->SetColor(Math::Vector4(i*2.55f, j*2.55f, 0, 1));
			((SpriteComponent*)clone->GetComponent(ComponentType::SpriteComponentType))->GetSprite()->SetTransform(clone->GetTransform());
			scene->AddGameObject(clone);
		}
	}
#endif

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!(window->IsClosed()))
	{
		window->Clear();
		shader->Enable();
		scene->Render();
		window->PollEventsAndSwapBuffers();

		frames++;
		if (time.Elapsed() - timer > 1.0f)
		{
			timer += 1;
			LOG_INFO("fps: ", frames);
			frames = 0;
		}
	}	
	return 0;
}