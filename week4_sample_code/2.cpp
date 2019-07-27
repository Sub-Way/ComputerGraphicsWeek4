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

	Vec3 colors[] =
	{
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(1.0, 1.0, 0.0),
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

	GLbyte inlines[] =
	{
	   0,1,
	   2,3,
	   4,5,
	};

	Vec3 vertices[] =
	{
	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 1.0, 0.0),
	   Vec3(1.0, 1.0, 1.0)
	};

	GLbyte indices[] =
	{
	   0,2,1,  0,3,2,
	   2,3,7,  3,7,6,
	   0,3,5,  3,5,6,
	   4,7,5,   7,5,6,
	   2,1,4,   2,4,7,
	   0,1,4,   0,4,5,
	}; //정육면체의 각 면의 조합

	GLuint vbo[4];
	glGenBuffers(3, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLbyte) * 36, indices, GL_STATIC_DRAW);



	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		//정육면체
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glColorPointer(3, GL_FLOAT, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glVertexPointer(3, GL_FLOAT, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, 0);

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}