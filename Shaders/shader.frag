#version 330 core

out vec4 color;
uniform vec2 light_pos;
uniform sampler2D textures[32];

in Data{
	vec4 position;
	vec2 uv;
	float texID;
	vec4 color;
} fs_in;

void main()
{
	float intensity = 1.0f/length(fs_in.position.xy - light_pos);
	vec4 texColor = fs_in.color;
	if(fs_in.texID > 0.0f)
	{
		int tid = int(fs_in.texID - 0.5);
		texColor = fs_in.color * texture(textures[tid], fs_in.uv);
	}
	color = texColor * intensity;
}