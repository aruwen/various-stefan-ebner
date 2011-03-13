varying float     LightIntensity;
varying vec3      MCposition;

uniform sampler3D Noise;
float noiseScale = 1.5;

void main(void)
{
	vec4  noisevec  = texture3D(Noise, noiseScale * MCposition);
//only use the highest frequency from the noise texture
    float intensity = min(1.0, noisevec[3] * 15.0);

    vec3  color     = vec3 (intensity * LightIntensity);

    gl_FragColor    = vec4 (color, 1.0);
}