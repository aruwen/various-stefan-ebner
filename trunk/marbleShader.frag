varying float     LightIntensity;
varying vec3      MCposition;

uniform sampler3D Noise;
vec3 marbleColor = vec3(0.7, 0.7, 0.89);
vec3 veinColor	= vec3(0.1, 0.1, 0.1);

void main(void)
{
	vec4 noisevec   = texture3D(Noise, MCposition);

    float intensity = abs(noisevec[0] - 0.25) +
                      abs(noisevec[1] - 0.125) +
                      abs(noisevec[2] - 0.0625) +
                      abs(noisevec[3] - 0.03125);
                      
    float sineval = sin(MCposition.y * 8.0 + intensity * 24.0) * 0.5 + 0.5;

    vec3 color    = mix(veinColor, marbleColor, sineval) * LightIntensity;

    gl_FragColor  = vec4 (color, 1.0);
}