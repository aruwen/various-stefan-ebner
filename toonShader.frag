varying vec3 vNormal; 
varying vec3 vVertex; 



void main (void) 
{ 
// not yet figured out how to use uniform to get this from the oF application
float silhouetteThreshold = 0.4;

// the 3 different colors
vec4 materialColor = vec4(0.7, 0.0, 0.0, 1.0);
vec4 silhouetteColor = vec4(0.0, 0.0, 0.0, 1.0); 
vec4 specularColor = vec4(0.9, 0.0, 0.0, 1.0);

vec3 eyePos = normalize(-vVertex); 
vec3 lightPos = gl_LightSource[0].position.xyz; 
vec3 Normal = vNormal; 

vec3 EyeVert = normalize(eyePos - vVertex); 
vec3 LightVert = normalize(lightPos - vVertex); 

vec3 EyeLight = normalize(LightVert+EyeVert); 

//silhouette calculation
float sil = max(dot(Normal,EyeVert), 0.0); 

if( sil < silhouetteThreshold ) 
  gl_FragColor = silhouetteColor; 
else 
{ 
  gl_FragColor = materialColor; 

  float spec = pow(max(dot(Normal,EyeLight),0.0), 5.0); 
  if( spec < 0.05 ) 
     gl_FragColor *= 0.9; 
  else 
     gl_FragColor = specularColor; 

  float diffuse = max(dot(Normal,LightVert),0.0); 
  if( diffuse < 0.3 ) 
     gl_FragColor *=0.8; 

} 
} 