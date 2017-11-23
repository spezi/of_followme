
uniform sampler2D texture1;  
uniform sampler2D texture2;  
varying vec2  TexCoord;  

void main(void)  
{  
  	// get texture info  
	vec4 v1 = texture2D(texture1, TexCoord);  
	vec4 v2 = texture2D(texture2, TexCoord);  
	gl_FragColor =  vec4(mix(v1, v2,0.5).rgb, 1.0);  

} 