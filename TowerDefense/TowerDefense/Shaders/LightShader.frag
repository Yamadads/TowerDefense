#version 330 core
struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
}; 

struct DirLight {
    vec3 direction;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

#define NR_POINT_LIGHTS 20

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform int pointsNumber;
uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform Material material;

void main()
{    
       // Properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    
       // Phase 1: Directional lighting  

	vec3 lightDir = normalize(-dirLight.direction);
    // Diffuse shading
    float diff = max(dot(norm, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Combine results
    vec3 ambient = dirLight.ambient * vec3(texture(material.texture_diffuse1, TexCoords));
    vec3 diffuse = dirLight.diffuse * diff * vec3(texture(material.texture_diffuse1, TexCoords));
    vec3 specular = dirLight.specular * spec * vec3(texture(material.texture_specular1, TexCoords));
    
	vec3 result = (ambient + diffuse + specular);

       // Phase 2: Point lights

    for(int i = 0; i < pointsNumber ; i++)
	{
		vec3 lightDir = normalize(pointLights[i].position - FragPos);
		// Diffuse shading
		float diff = max(dot(norm, lightDir), 0.0);
		// Specular shading
		vec3 reflectDir = reflect(-lightDir, norm);
		float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
		// Attenuation
		float distance = length(pointLights[i].position - FragPos);
		float attenuation = 1.0f / (pointLights[i].constant + pointLights[i].linear * distance + pointLights[i].quadratic * (distance * distance));    
		// Combine results
		vec3 ambient = pointLights[i].ambient * vec3(texture(material.texture_diffuse1, TexCoords));
		vec3 diffuse = pointLights[i].diffuse * diff * vec3(texture(material.texture_diffuse1, TexCoords));
		vec3 specular = pointLights[i].specular * spec * vec3(texture(material.texture_specular1, TexCoords));
		ambient *= attenuation;
		diffuse *= attenuation;
		specular *= attenuation;
		result += (ambient + diffuse + specular);
	}
    
    color = vec4(result, 1.0);	
}