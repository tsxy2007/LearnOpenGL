#version 330 core
layout (location = 0) in vec3 position;
out vec4 vextexColor;
void main()
{
 gl_Position = vec4(position,1.0f);
 vextexColor = vec4(position,1.0f);// vec4(0.5f,0.0f,0.0f,1.0f);
}