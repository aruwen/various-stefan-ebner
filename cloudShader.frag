varying float     LightIntensity;
varying vec3      MCposition;

uniform sampler3D Noise;
vec3      SkyColor   = vec3(0.0, 0.0, 0.85);
vec3      CloudColor = vec3(0.85, 0.85, 0.9);

void main(void)
{
// get noise on the current position stored in the vertex shader
    vec4  noisevec  = texture3D(Noise, MCposition);
// intensity is computed by adding all the 4 values in the noise texture
// as well as adding an additional 0.3125 to account for the average
// values at a higher frequency
// finally scale the value to use up more of the range from 0...1
    float intensity = (noisevec[0] + noisevec[1] +
                       noisevec[2] + noisevec[3] + 0.03125) * 1.5;

// now blend the 2 colors
    vec3 color   = mix(SkyColor, CloudColor, intensity) * LightIntensity;

   gl_FragColor = vec4(color, 1.0);
}