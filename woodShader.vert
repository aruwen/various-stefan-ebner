varying float LightIntensity;
varying vec3  MCposition;

vec3  LightPos;
float Scale = 2.0;

void main()
{
	LightPos		= gl_LightSource[0].position.xyz; 
    vec3 ECposition = vec3(gl_ModelViewMatrix * gl_Vertex);
    MCposition      = vec3(gl_Vertex) * Scale;
    vec3 tnorm      = normalize(vec3(gl_NormalMatrix * gl_Normal));
    LightIntensity  = dot(normalize(LightPos - ECposition), tnorm);
    LightIntensity *= 1.5;
    gl_Position     = ftransform();
}