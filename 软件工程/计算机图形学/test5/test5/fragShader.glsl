#version 430

layout (binding=0) uniform sampler2D tex;

in vec2 uv;

void main()
{
	gl_FragColor = vec4( texture2D( tex, uv).rgb, 1.0);
}
