#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 lightPosition;

out vec4 l;
out vec4 n;
out vec4 v;
//out vec4 interpolatedColor;
out vec2 iTexCoord;

void main()
{
	vec4 pos=vec4(position,1.0f);
	vec4 nor=vec4(normal,1.0f);
    gl_Position = projection * view * model * pos;//vec4(position, 1.0f);
	l=normalize(view*(lightPosition-model*pos));
	n=normalize(view*model*nor);
	v=normalize(vec4(0,0,0,1)-view*model*pos);
    iTexCoord = texCoords;
}