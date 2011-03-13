// define 2 varying variables, direction of incoming light and normal of the current vertex
varying vec3 lightDir, normal;

void main()
{
	lightDir = normalize(vec3(gl_LightSource[0].position));
	normal = gl_NormalMatrix * gl_Normal;
	
	gl_Position = ftransform();

}