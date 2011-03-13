varying float     LightIntensity;
varying vec3      MCposition;

uniform sampler3D Noise;
vec3 yellow = vec3(0.8, 0.7, 0.0);
vec3 red	= vec3(0.6, 0.1, 0.0);
float noiseScale = 1.2;

void main(void)
{
//scale each noise value
	vec4 noisevec = texture3D(Noise, MCposition * noiseScale);
// then move it to the center at 0 and take the absolut value
    float intensity = abs(noisevec[0] - 0.25) +
                      abs(noisevec[1] - 0.125) +
                      abs(noisevec[2] - 0.0625) +
                      abs(noisevec[3] - 0.03125);
// scale the values to get in the range of 0...1
// then clamp them
    intensity    = clamp(intensity * 6.0, 0.0, 1.0);

    vec3 color   = mix(yellow, red, intensity) * LightIntensity;

    gl_FragColor = vec4 (color, 1.0);
}