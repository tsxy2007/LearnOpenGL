#include "ggl.h"
#include "Scene.h"

#define GLEW_STATIC
const GLuint WIDTH = 800,HEIGHT = 600;

void key_callback(GLFWwindow* window,int key,int scancode , int action ,int mode);

int main()
{
	// ��ʼ��glfw��glfw��Ҫ�ײ㴰�ڻ��ƣ�����һЩ�������ԣ�
	glfwInit();
	//������Ŀ֧�����汾
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	//������Ŀ֧�ֵ���С�汾
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

	////ȫ����Ҫ���monitor
	//GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	//if (monitor)
	//{
	//	const GLFWvidmode* mode=glfwGetVideoMode(monitor);
	//	glfwWindowHint(GLFW_RED_BITS,mode->redBits);
	//	glfwWindowHint(GLFW_GREEN_BITS,mode->greenBits);
	//	glfwWindowHint(GLFW_BLUE_BITS,mode->blueBits);
	//	glfwWindowHint(GLFW_REFRESH_RATE,mode->refreshRate);
	//}

	//glfwWindowHint(GLFW_DEPTH_BITS,8);
	//glfwWindowHint(GLFW_STENCIL_BITS,24);
	//glfwWindowHint(GLFW_DOUBLEBUFFER,GL_TRUE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	//��������
	GLFWwindow* window=glfwCreateWindow(WIDTH,HEIGHT,"LearnOpenGL",nullptr,nullptr);
	if(window==nullptr)
	{
		std::cout<<"Failed to create GLFW window"<<std::endl;
		glfwTerminate();
		return -1;
	}
	//����opengl���ڵ�������
	glfwMakeContextCurrent(window);
	glewExperimental=GL_TRUE;
	//��ʼ��glew
	if(glewInit()!=GLEW_OK)
		return -1;

	int width,height;
	//��ȡ���ڴ�С
	glfwGetFramebufferSize(window,&width,&height);
	//���ð����¼�
	glfwSetKeyCallback(window,key_callback);
	//���ô���ϵ��
	glViewport(0,0,width,height);
	//�Զ����ʼ������
	Init();
	//�ж��Ƿ�Ӧ�ùر�
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		//���ƹ���
		Draw();
		//����������
		glfwSwapBuffers(window);
	}
	//�˳�����
	glfwTerminate();
	return 0;
}
void key_callback(GLFWwindow* window,int key,int scancode , int action ,int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window,GL_TRUE);
	}
}