#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GL\GLU.h>
#include <iostream>

int width = 640;
int height = 480;

class Vec3 {
public:
	union {
		struct { float x_, y_, z_; };
		struct { float r_, g_, b_; };
		float v_[3];
	};
	Vec3(const float& a, const float& b, const float& c)
		:x_(a), y_(b), z_(c)
	{}
};

int main()
{
	GLFWwindow* window;
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(width, height, "week 4 sample", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return -1;
	}

	glClearColor(0.8f, 0.8f, 0.8f, 1);
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	const float aspect_ratio = (float)width / (float)height;
	glOrtho(-2.0 * aspect_ratio, 2.0 * aspect_ratio, -2.0, 2.0, -5.0, 5.0);
	gluLookAt(1, 1, 1, 0.5, 0.5, 0.5, 0.0, 0.1, 0);

	glEnable(GL_DEPTH_TEST);

	Vec3 colors[] =
	{
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),

	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),

	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),

	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),

	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),

	};

	Vec3 lines_color[] =
	{
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	};

	Vec3 lines[] =
	{
	   Vec3(0.0, 0.0, 0.0),
	   Vec3(5.0, 0.0, 0.0),

	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 5.0, 0.0),

	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 0.0, 5.0),
	};

	Vec3 vertices[] =
	{
		//¿ÞÂÊ ¿· ¸é
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 1.0),
		Vec3(0.0, 1.0, 1.0),
		Vec3(0.0, 1.0, 1.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(0.0, 0.0, 0.0),

		//¹Ù´Ú¸é
		Vec3(1.0, 0.0, 1.0),
		Vec3(0.0, 0.0, 1.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(1.0, 0.0, 0.0),
		Vec3(1.0, 0.0, 1.0),

		//¿À¸¥ÂÊ ¿· ¸é
		Vec3(1.0, 0.0, 1.0),
		Vec3(1.0, 0.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(1.0, 0.0, 1.0),

		//¾Õ ¸é
		Vec3(0.0, 0.0, 1.0),
		Vec3(1.0, 0.0, 1.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(0.0, 1.0, 1.0),
		Vec3(0.0, 0.0, 1.0),

		//À­¸é
		Vec3(0.0, 1.0, 1.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(0.0, 1.0, 1.0),

		//µÞ¸é
		Vec3(1.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 0.0, 0.0),

		//ÁÂÇ¥Ãà
		Vec3(0.0, 0.0, 0.0),
		Vec3(5.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 5.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 5.0),

	};

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Á¤À°¸éÃ¼
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		glColorPointer(3, GL_FLOAT, 0, colors[0].v_);
		glVertexPointer(3, GL_FLOAT, 0, vertices);

		glDrawArrays(GL_TRIANGLES, 0, 36);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		//ÁÂÇ¥Ãà
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		glColorPointer(3, GL_FLOAT, 0, lines_color[0].v_);
		glVertexPointer(3, GL_FLOAT, 0, lines);

		glDrawArrays(GL_LINES, 0, 6);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}