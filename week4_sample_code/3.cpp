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
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	};

	Vec3 vertices[] =
	{
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 2.0, 1.0),
	   Vec3(1.5, 0.0, 1.5),
	};

	Vec3 lines_color[] =
	{
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
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

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		const int triangle_num = 20000;
		float dtheta = 3.141592 / triangle_num;
		float r = 0.5;
		float theta = 0;

		for (int i = 0; i <= triangle_num; i++, theta += dtheta * 2) {

			glColorPointer(3, GL_FLOAT, 0, colors[0].v_);
			glVertexPointer(3, GL_FLOAT, 0, vertices);

			vertices[2].x_ = r * sin(theta) + vertices->x_;
			vertices[2].z_ = r * cos(theta) + vertices->z_;

			glDrawArrays(GL_TRIANGLE_FAN, 0, 3);
		}

		//ÁÂÇ¥Ãà

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