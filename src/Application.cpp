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

void PrintLog(std::string log) {
	
}


struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static struct ShaderProgramSource ParseShader(const std::string& file){
	enum ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::ifstream stream(file);
	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while(getline(stream, line)) {
		if(line.empty() || line.rfind("//",0) != std::string::npos){ } // Skip the line
		else if(line.find("#shader") != std::string::npos){
			if(line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if(line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		} else {
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}


static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // Error handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    //std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader compile status: " << result << std::endl;
    if ( result == GL_FALSE )
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout 
            << "Failed to compile "
            << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
            << "shader"
            << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    // create a shader program
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    GLint program_linked;

    glGetProgramiv(program, GL_LINK_STATUS, &program_linked);

    // std::cout << "Program link status: " << program_linked << std::endl;
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(program, 1024, &log_length, message);
        // std::cout << "Failed to link program" << std::endl;
        // std::cout << message << std::endl;
    }

    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
	time_t ttime = time(0);
	char* dt;
	dt = strtok(ctime(&ttime), "\n");

	if(!glfwInit()){
		// Failed to initialize GLFW, print error and quit.
		fprintf(stderr, "[!] Failed to initialize GLFW!\n");
		getchar();
		return -1;
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
		return -1;
	} else { std::cout << "\033[1;32m[+] Created GLFW window successfully!\033[0m\n"; }

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if(glewInit() != GLEW_OK){
		fprintf(stderr, "[!] Failed to initialize GLEW!\n");
		getchar();
		glfwTerminate();
		return -1;
	} else {  std::cout << "\033[1;32m[+] Initialized GLEW successfully!\033[0m\n"; }

	// Ensure that the escape key can be captured
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue Background color 
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	float positions[6] = {
	    -0.5f, -0.5f,
	     0.0f,  0.5f,
	     0.5f, -0.5f
	};

	// Create buffer and copy data
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	// Define vertex layout
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	ShaderProgramSource source = ParseShader("/home/cryptigo/Development/C++/GL/src/res/shaders/Basic.shader");

	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);


	// For FPS calculation
	double lastTime = glfwGetTime();
	int nbFrames = 0;

	do {
		// Set window title 
		double currentTime = glfwGetTime();
		double delta = currentTime - lastTime;
		nbFrames++;
		if(delta >= 1.0) {
			int fps = int(nbFrames) / delta;

			std::stringstream ss;
			ss << "OpenGL Program" << " - " << "V1.0" << " - " << "[" << fps << " FPS]";

			glfwSetWindowTitle(window, ss.str().c_str());
		}
		// 

		// Clear the screen.
		glClear(GL_COLOR_BUFFER_BIT);

		// Render here!
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Swap Buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
	
	// Clean up
	glDeleteBuffers(1, &buffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(shader);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;






	return 0;
}


