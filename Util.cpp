#include "ggl.h"
unsigned char* LoadFileContent(const char* FilePath,int& fileSize)
{
	unsigned char* fileContent = nullptr;
	FILE* pFile;
	fopen_s(&pFile,FilePath,"rb");
	if (pFile)
	{
		fseek(pFile,0,SEEK_END);
		int nLen = ftell(pFile);
		if (nLen > 0)
		{
			rewind(pFile);
			fileContent = new unsigned char[nLen+1];
			fread_s(fileContent,nLen,sizeof(unsigned char),nLen,pFile);
			fileContent[nLen] = '\0';
		}
	}
	
	return fileContent;
}

GLuint CreateShader(const char* FilePath,GLenum ShaderType)
{
	int FileSize=0;
	GLint Result;
	//加载shader文件
	const GLchar* shaderSource=(const GLchar*)LoadFileContent(FilePath,FileSize);
	//创建一个shader对象
	GLuint shader=glCreateShader(ShaderType);
	//shader文件与shader对象关联起来
	glShaderSource(shader,1,&shaderSource,NULL);
	//编译shader
	glCompileShader(shader);
	//检查编译状态
	glGetShaderiv(shader,GL_COMPILE_STATUS,&Result);
	//如果失败打印信息，并且删除shander对象
	if (Result == GL_FALSE)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(shader,512,NULL,infoLog);
		glDeleteShader(shader);
		shader = 0;
	}

	return shader;
}

GLuint CreateShaderProgram(ShaderInfo* source,int Lenght)
{
	//创建shader程序
	GLint program = glCreateProgram();
	for (int i = 0 ;i<Lenght;i++)
	{
		//创建shader对象
		source[i].Shader = CreateShader(source[i].FilePath,source[i].ShaderType);
		//关联shader对象与shader程序
		glAttachShader(program,source[i].Shader);
		//删除shader对象
		glDeleteShader(source[i].Shader);
	}
	//link shader程序
	glLinkProgram(program);
	GLint Result;
	//获取状态如果错误删除
	glGetProgramiv(program,GL_LINK_STATUS,&Result);
	if (Result == GL_FALSE)
	{
		GLchar infoLog[512];
		glGetProgramInfoLog(program,512,NULL,infoLog);
		std::cout<<"ERROR::SHADER::shaderProgram::COMPILATION_FAILED\n"<<infoLog<<std::endl;
		glDeleteProgram(program);
		program = 0;
	}
	return program;
}