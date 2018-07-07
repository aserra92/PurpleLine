#version 400 core

uniform transform {
	mat4 ModelViewMatrix;
	mat4 ProjectionMatrix;
	mat4 InfProjectionMatrix;
	mat4 MVPMatrix;
	vec4 Viewport;
} Transform;

uniform sampler2D Heightmap;

uniform vec3 TerrainInfo;
uniform vec2 Offset;
uniform vec3 FogColor;

layout(location = 0) in vec2 VertexPosition;

out vec2 GlobalTexCoord;
out vec2 LocalTexCoord;
out vec4 FogParam;

void main(void) {

	/* calculate texture coordinates */
	GlobalTexCoord = VertexPosition / TerrainInfo.x;
	LocalTexCoord = VertexPosition / TerrainInfo.y;
	
	/* calculate terrain height */
	float Height = texture( Heightmap, GlobalTexCoord ).r;

	/* view space position */
	vec4 ViewSpacePosition = Transform.ModelViewMatrix * vec4(VertexPosition.x + Offset.x, Height * TerrainInfo.z, VertexPosition.y + Offset.y, 1.0);

	/* calculate fog */
	FogParam.xyz = FogColor;
	FogParam.w = clamp( (length(ViewSpacePosition.xyz) - 900.0) / 100.0, 0, 1);

	/* transform into clip space */
	gl_Position = Transform.ProjectionMatrix * ViewSpacePosition;
	
}
