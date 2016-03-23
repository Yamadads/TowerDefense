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
	vec4 La=vec4(0,0,0,0);
	vec4 Ma=vec4(0,0,0,0);

	vec4 Ld=vec4(1,1,1,1);
	vec4 Md=texture(texture_diffuse1,iTexCoord);

	vec4 Ls=vec4(1,1,1,1);
	vec4 Ms=texture(texture_diffuse1,iTexCoord);

	float shininess=100;

	vec4 ml=normalize(l);
	vec4 mn=normalize(n);
	vec4 mv=normalize(v);
	vec4 mr=reflect(-ml,mn);

	float nl=max(dot(ml,mn),0);
	float rv=pow(max(dot(mr,mv),0),shininess);


    color = La*Ma+Ld*Md*vec4(nl,nl,nl,1)+Ls*Ms*vec4(rv,rv,rv,0);
}