#version 330 core
out vec4 color;
uniform vec4 ourColor;
in vec4 vextexColor;
void main()
{
	color = vextexColor;
}