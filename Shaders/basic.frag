#version 330 core

out vec4 color;


in Data{
	vec4 color;
} fs_in;

void main(){
  color = fs_in.color;
}