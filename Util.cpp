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
	//����shader�ļ�
	const GLchar* shaderSource=(const GLchar*)LoadFileContent(FilePath,FileSize);
	//����һ��shader����
	GLuint shader=glCreateShader(ShaderType);
	//shader�ļ���shader�����������
	glShaderSource(shader,1,&shaderSource,NULL);
	//����shader
	glCompileShader(shader);
	//������״̬
	glGetShaderiv(shader,GL_COMPILE_STATUS,&Result);
	//���ʧ�ܴ�ӡ��Ϣ������ɾ��shander����
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
	//����shader����
	GLint program = glCreateProgram();
	for (int i = 0 ;i<Lenght;i++)
	{
		//����shader����
		source[i].Shader = CreateShader(source[i].FilePath,source[i].ShaderType);
		//����shader������shader����
		glAttachShader(program,source[i].Shader);
		//ɾ��shader����
		glDeleteShader(source[i].Shader);
	}
	//link shader����
	glLinkProgram(program);
	GLint Result;
	//��ȡ״̬�������ɾ��
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