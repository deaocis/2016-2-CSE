#include <GLFW/glfw3.h>
#include <algorithm>

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawBox(const int& i_c, const int& j_c)
{
	const int thickness = 10;

	for (int j = j_c - thickness; j < j_c + thickness; j++)
		for (int i = i_c - thickness; i < i_c + thickness; i++)
		{
			drawPixel(i, j, 1.0f, 1.0f, 0.0f);
		}
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "GLFW Test", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width*height * 3, 1.0f);	// white background

         //선 그릴수 있음.
		drawLine(200, 200, 500, 200, 0.0f, 0.0f, 1.0f);

		//for(int j=100;j<300;j++)
		//	for (int i = 100; i < 300; i++)
		//	{
		//		pixels[(i + width*j) * 3 + 0] = 0.0f;
		//		pixels[(i + width*j) * 3 + 1] = 1.0f;
		//		pixels[(i + width*j) * 3 + 2] = 0.0f;
		//	}

		drawBox(100, 100);





		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		//We do that.


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;

	glfwTerminate();
	return 0;
}