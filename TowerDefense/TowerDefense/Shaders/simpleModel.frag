#version 330 core

in vec4 l;
in vec4 n;
in vec4 v;
//in vec4 interpolatedColor;
in vec2 iTexCoord;

out vec4 color;

uniform sampler2D texture_diffuse1;

void main()
{    
	
    color = texture(texture_diffuse1, iTexCoord);
}