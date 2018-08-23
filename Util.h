#pragma once

typedef struct 
{
	const char* FilePath;
	GLenum ShaderType;
	GLuint Shader;
}ShaderInfo;

unsigned char* LoadFileContent(const char* FilePath,int& fileSize);

GLuint CreateShader(const char* FilePath,GLenum ShaderType);

GLuint CreateShaderProgram(ShaderInfo* source,int Lenght);