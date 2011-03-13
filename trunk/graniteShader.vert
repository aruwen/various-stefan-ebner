varying float LightIntensity;
varying vec3  MCposition;

vec3  LightPos;

float Scale = 1.5;

void main()
{
	LightPos		= gl_LightSource[0].position.xyz; 
    vec3 ECposition = vec3(gl_ModelViewMatrix * gl_Vertex);
    
    // the incoming vertex value, available to the fragment shader
    // used for the input value when looking up the 3d texture
    // and scaling the object in relationship to the sicze of the noise texture
    MCposition      = vec3(gl_Vertex) * Scale;
    vec3 tnorm      = normalize(vec3(gl_NormalMatrix * gl_Normal));
    LightIntensity  = dot(normalize(LightPos - ECposition), tnorm);
    
    //increase the amount of illumination
    LightIntensity *= 1.5;
    gl_Position     = ftransform();
}