varying vec3 lightDir, normal;

void main()
{
	// intensity of incoming light and the resulting color
	float intensity;
	vec4 color;
	
	//just to be sure the normal is normalized
	vec3 n = normalize(normal);
	
	// intensity from the interpolated light direction as well as the normal
	intensity = max(dot(lightDir, n), 0.0);
	
	//set color according to intensity
	if(intensity > 0.99)
		color = vec4(0.9, 0.9, 1.0, 1.0);
	else if(intensity > 0.95)
		color = vec4(0.7, 0.7, 1.0, 1.0);
	else if(intensity > 0.5)
		color = vec4(0.3, 0.3, 0.6, 1.0);
	else if(intensity > 0.25)
		color = vec4(0.2, 0.2, 0.4, 1.0);
	else 
		color = vec4(0.1, 0.1, 0.2, 1.0);

gl_FragColor = color;
}