// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include <string.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Renderer.h"

void PrintLog(std::string log) {
	
}


GLFWwindow* InitWindow(){
	time_t ttime = time(0);
	char* dt;
	dt = strtok(ctime(&ttime), "\n");

	if(!glfwInit()){
		// Failed to initialize GLFW, print error and quit.
		fprintf(stderr, "[!] Failed to initialize GLFW!\n");
		getchar();
		return nullptr;
	} else { std::cout << "\033[1;36m" << dt << "\033[1;36m" << "[+] Initialized GLFW successfully!\033[0m\n"; }

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Use modern OpenGL

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(1024, 768, "OpenGL Window", NULL, NULL);
	if(window == NULL){
		// Failed to create GLFW window, print error and quit.
		fprintf(stderr, "[!] Failed to create GLFW Window!\n");
		getchar();
		glfwTerminate();
		return nullptr;
	} else { std::cout << "\033[1;32m[+] Created GLFW window successfully!\033[0m\n"; }

	glfwMakeContextCurrent(window);

		
	// Initialize GLEW
	if(glewInit() != GLEW_OK){
		fprintf(stderr, "[!] Failed to initialize GLEW!\n");
		getchar();
		glfwTerminate();
		return nullptr;
	} else {  std::cout << "\033[1;32m[+] Initialized GLEW successfully!\033[0m\n"; }

	// Ensure that the escape key can be captured
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	return window;

}

int main(void)
{
	GLFWwindow* window = InitWindow();
	if(!window)
		return -1;


	// Dark blue Background color 
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	float positions[] = {
        -0.5f, -0.5f, // 0
         0.5f, -0.5f, // 1
         0.5f,  0.5f, // 2
        -0.5f,  0.5f  // 3
    };

	unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };


	{
		VertexArray va;
		VertexBuffer vb(positions, 4 * 2 * sizeof(float));
		IndexBuffer ib(indices, 6);

		VertexBufferLayout layout;
		layout.AddFloat(2);

		va.AddBuffer(vb, layout);

		Shader shader("/home/cry/dev/C++/opengl-program/src/res/shaders/Basic.shader");
		shader.Bind();

		float red = 0.0f;
		float step = 0.05f;

		Renderer renderer;

		do {
			renderer.Clear();

			shader.Bind();
			shader.SetUniform4f("u_Color", red, 0.3, 0.8, 1.0);

			renderer.Draw(va, ib, shader);

			glfwSwapBuffers(window);
			glfwPollEvents();

			if(red < 0.0f || red > 1.0f)
				step *= -1.0;
			red += step;
		} while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
					glfwWindowShouldClose(window) == 0);
	}
	

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;

}


