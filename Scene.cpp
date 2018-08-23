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
	glGenBuffers(1,&EBO); // 创建EBO 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);//绑定当前EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);//绑定数据
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);//解绑当前EBO
	glGenVertexArrays(1,&VAO);//创建VAO存储缓冲区和顶点属性状态。
	glBindVertexArray(VAO);//绑定当前VAO
	glGenBuffers(1,&VBO);//创建VBO一个调用显存并存储所有顶点数据供显卡使用的缓冲对象。
	glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定当前VBO
	glBufferData(GL_ARRAY_BUFFER,sizeof(verteices),verteices,GL_STATIC_DRAW);//VBO绑定数据
	//glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(verteices),verteices);//绑定部分数据
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);//通过VAO绑定数据到Shader
	glEnableVertexAttribArray(0);//启用这种格式
	glBindBuffer(GL_ARRAY_BUFFER,0);//解绑VBO
	glBindVertexArray(0);//解绑VAO
	ShaderInfo shaderSource[] = 
	{
		{"Simple.vs",GL_VERTEX_SHADER},
		{"Simple.fs",GL_FRAGMENT_SHADER}
	}; // shader源文件以及类型（vertex shader和fragment shader）
	//创建shader program
	shaderProgram=CreateShaderProgram(shaderSource,2);
	glUseProgram(shaderProgram);
	//获取shader的属性值
	vertexColorLocation=glGetUniformLocation(shaderProgram,"ourColor");
}

void Draw()
{
	glClearColor(0.2f,0.3f,0.3f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glUniform4f(vertexColorLocation,1.f,0.f,0.0f,1.0f);
	glBindVertexArray(VAO);//绑定当前VAO
	//glDrawArrays(GL_TRIANGLES,0,6);//通过VAO绘制
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);//通过索引绘制程序
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);
	glBindVertexArray(0);//解绑VAO

}
