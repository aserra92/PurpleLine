#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

out Data{
	vec4 color;
} vs_out;

void main()
{
	gl_Position = position;
	vs_out.color = color;
}