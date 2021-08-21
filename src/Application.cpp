#include <unistd.h>
#define GetCurrentDir getcwd


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
#include "Texture.h"

#include "constants.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
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
        100.0f, 100.0f, 0.0f, 0.0f, // 0
        200.0f, 100.0f, 1.0f, 0.0f, // 1
        200.0f, 200.0f, 1.0f, 1.0f, // 2
        100.0f, 200.0f, 0.0f, 1.0f  // 3
    };

	unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLCall( glEnable(GL_BLEND) );
    GLCall( glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) );

	{
		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));
		IndexBuffer ib(indices, 6);

		glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

		glm::mat4 ident = glm::mat4(1.0f);
        glm::vec3 trvec = glm::vec3(-100, 0, 0);
        glm::mat4 view = glm::translate(ident, trvec);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));

        glm::mat4 mvp = proj * view * model;

		VertexBufferLayout layout;
		layout.AddFloat(2);
		layout.AddFloat(2);

		va.AddBuffer(vb, layout);
		//std::string cwd = get_current_dir();
		//cwd.erase(cwd.end()-9, cwd.end(), 9)
		
		//std::cout << cwd << std::endl;
		Shader shader("../../src/res/shaders/Basic.shader");
		shader.SetUniformMat4f("u_MVP", mvp);
		shader.Bind();

		Texture texture("../../src/res/textures/Lenna.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		Renderer renderer;

		do {
			renderer.Clear();

			shader.Bind();

			renderer.Draw(va, ib, shader);

			glfwSwapBuffers(window);
			glfwPollEvents();


		} while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
					glfwWindowShouldClose(window) == 0);
	}
	

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;

}


