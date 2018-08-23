#include "Scene.h"
#include "ggl.h"

GLfloat verteices[] = 
{
	-0.5f,-0.5f,0.0f,
	0.5f,-0.5f,0.0f,
	0.5f,0.5f,0.f,
	-0.5f,0.5f,0.f
};

GLushort indexs[] = 
{
	0,1,2,
	0,2,3
};
GLuint VBO,VAO,EBO;
GLuint shaderProgram;
GLint vertexColorLocation;
void Init()
{
	glGenBuffers(1,&EBO); // ����EBO 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);//�󶨵�ǰEBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);//������
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);//���ǰEBO
	glGenVertexArrays(1,&VAO);//����VAO�洢�������Ͷ�������״̬��
	glBindVertexArray(VAO);//�󶨵�ǰVAO
	glGenBuffers(1,&VBO);//����VBOһ�������Դ沢�洢���ж������ݹ��Կ�ʹ�õĻ������
	glBindBuffer(GL_ARRAY_BUFFER,VBO);//�󶨵�ǰVBO
	glBufferData(GL_ARRAY_BUFFER,sizeof(verteices),verteices,GL_STATIC_DRAW);//VBO������
	//glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(verteices),verteices);//�󶨲�������
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);//ͨ��VAO�����ݵ�Shader
	glEnableVertexAttribArray(0);//�������ָ�ʽ
	glBindBuffer(GL_ARRAY_BUFFER,0);//���VBO
	glBindVertexArray(0);//���VAO
	ShaderInfo shaderSource[] = 
	{
		{"Simple.vs",GL_VERTEX_SHADER},
		{"Simple.fs",GL_FRAGMENT_SHADER}
	}; // shaderԴ�ļ��Լ����ͣ�vertex shader��fragment shader��
	//����shader program
	shaderProgram=CreateShaderProgram(shaderSource,2);
	glUseProgram(shaderProgram);
	//��ȡshader������ֵ
	vertexColorLocation=glGetUniformLocation(shaderProgram,"ourColor");
}

void Draw()
{
	glClearColor(0.2f,0.3f,0.3f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glUniform4f(vertexColorLocation,1.f,0.f,0.0f,1.0f);
	glBindVertexArray(VAO);//�󶨵�ǰVAO
	//glDrawArrays(GL_TRIANGLES,0,6);//ͨ��VAO����
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);//ͨ���������Ƴ���
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);
	glBindVertexArray(0);//���VAO

}
