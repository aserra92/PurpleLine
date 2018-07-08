#version 330 core
layout (location = 0) in vec4 position;
uniform vec4 color = vec4(0,0,1,0);

out Data{
	vec4 color;
} vs_out;

void main()
{
	gl_Position = position;
	vs_out.color = color;
}