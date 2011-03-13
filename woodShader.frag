varying float LightIntensity;
varying vec3  MCposition;

uniform sampler3D Noise;

vec3  LightWood = vec3(0.81, 0.36, 0.25);
vec3  DarkWood = vec3(0.54, 0.27, 0.07);
float RingFreq = 2.0;
vec3  NoiseScale = vec3(0.5, 0.1, 0.1);
//value that contributes to the noise
float Noisiness = 1.2;
float GrainScale = 25.0;

void main()
{
// scale the 3d texture position with the noisesclae and use that as an index
    vec3 noisevec = vec3(texture3D(Noise, MCposition * NoiseScale) * Noisiness);
// adding the noise to our current position
// the x coordinate will be added the low frequency ([0]) of our noise
// and to the x the third frequency of our noise
// giving us rings that are vaguely ring shaped but with some variation in width
// and distance from the center
    vec3 location = MCposition + noisevec;

// gives us the distance from the center, then multiplied by the amount of rings
// to get some rings into it
    float dist = sqrt(location.x * location.x + location.z * location.z);
    dist *= RingFreq;

// a function that goes from 0 up to 1.0 by adding 3 noise octaves to our distance
// then scale it by 2 to get a higher range and finally "clamping" it back to 0 to 1
    float r = fract(dist + noisevec[0] + noisevec[1] + noisevec[2]) * 2.0;

    if (r > 1.0)
        r = 2.0 - r;

//mix up the 2 colors, linear blend based on our computed value r
    vec3 color = mix(LightWood, DarkWood, r);
  
    color *= LightIntensity;
    gl_FragColor = vec4(color, 1.0);
}

 


