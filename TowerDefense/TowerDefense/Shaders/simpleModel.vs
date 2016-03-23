#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 iTexCoord;

void main()
{
	vec4 pos=vec4(position,1.0f);
	vec4 nor=vec4(normal,1.0f);
    gl_Position = projection * view * model * pos;
    iTexCoord = texCoords;
}