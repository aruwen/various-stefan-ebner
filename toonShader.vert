varying vec3 vNormal; 
varying vec3 vVertex; 

void main(void) 
{ 
	// fixed vertex transformation in the gpu ->
   gl_Position = ftransform(); 
   
   vVertex = vec3(gl_ModelViewMatrix * gl_Vertex); 
   vNormal = normalize(gl_NormalMatrix * gl_Normal); 
} 