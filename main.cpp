#include "ggl.h"
#include "Scene.h"

#define GLEW_STATIC
const GLuint WIDTH = 800,HEIGHT = 600;

void key_callback(GLFWwindow* window,int key,int scancode , int action ,int mode);

int main()
{
	// 初始化glfw（glfw主要底层窗口绘制，设置一些基本属性）
	glfwInit();
	//设置项目支持最大版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	//设置项目支持的最小版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

	////全屏需要添加monitor
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
	//创建窗口
	GLFWwindow* window=glfwCreateWindow(WIDTH,HEIGHT,"LearnOpenGL",nullptr,nullptr);
	if(window==nullptr)
	{
		std::cout<<"Failed to create GLFW window"<<std::endl;
		glfwTerminate();
		return -1;
	}
	//创建opengl窗口的上下文
	glfwMakeContextCurrent(window);
	glewExperimental=GL_TRUE;
	//初始化glew
	if(glewInit()!=GLEW_OK)
		return -1;

	int width,height;
	//获取窗口大小
	glfwGetFramebufferSize(window,&width,&height);
	//设置按键事件
	glfwSetKeyCallback(window,key_callback);
	//设置窗口系数
	glViewport(0,0,width,height);
	//自定义初始化数据
	Init();
	//判断是否应该关闭
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		//绘制过程
		Draw();
		//交换缓存区
		glfwSwapBuffers(window);
	}
	//退出程序
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