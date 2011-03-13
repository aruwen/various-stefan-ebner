uniform sampler2D texture;
uniform sampler2D normalTexture;

vec3 lightPos;

void main(void)
{
// lookup the normal from the normal texture, move from [0,1] to  [-1, 1] range and then normalize
	vec3 normal = texture2D(normalTexture, gl_TexCoord[0].st).rgb * 2.0 - 1.0;
	normal = normalize(normal)*0.5;  
  
	//lightPos		= normalize(gl_LightSource[0].position.xyz); 
  lightPos = normalize(vec3(1.0, 1.0, 1.5));
//diffuse color according to lightning
	float diffuse = max(dot(normal, lightPos), 0.0);  
	vec3 color = diffuse * texture2D(texture, gl_TexCoord[0].st).rgb;  
   
	gl_FragColor = vec4(color, 1.0);  
}