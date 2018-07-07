#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in float texID;
layout (location = 3) in vec4 color;

out Data{
	vec4 position;
	vec2 uv;
	float texID;
	vec4 color;
} vs_out;

uniform mat4 model = mat4(1.0f);
uniform mat4 view = mat4(1.0f);
uniform mat4 projection;

void main()
{
	gl_Position = projection * view *  model * position;
	vs_out.position =  model * position;
	vs_out.uv = uv;
	vs_out.texID = texID;
	vs_out.color = color;
}