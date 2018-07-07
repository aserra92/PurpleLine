#version 400 core

uniform sampler2D DecalTexture;
uniform sampler2D DetailTexture;

in vec2 GlobalTexCoord; 
in vec2 LocalTexCoord;
in vec4 FogParam;

layout(location = 0) out vec4 FragmentColor;

void main(void)
{
	/* fetch main decal texture */
	FragmentColor = texture( DecalTexture, GlobalTexCoord );
	
	/* add detail texture */
	FragmentColor += (texture( DetailTexture, LocalTexCoord ).r - 0.5) * 2.0;

	/* finally apply fog */
  	FragmentColor = mix( FragmentColor, FogParam, FogParam.w );

}
