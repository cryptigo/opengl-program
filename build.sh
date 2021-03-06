#!/bin/bash
PWD=${pwd}

CC=g++
BIN_DIR="../build/bin"
OBJ_DIR="../build/obj"

PROGRAM_NAME="OpenGLProgram"

SRC_FILES="IndexBuffer.cpp  Renderer.cpp Shader.cpp VertexArray.cpp VertexBuffer.cpp Texture.cpp"
OBJ_FILES="../build/obj/VertexBuffer.o ../build/obj/VertexArray.o ../build/obj/IndexBuffer.o ../build/obj/Shader.o ../build/obj/Renderer.o ../build/obj/stb_image.o ../build/obj/Texture.o"
CPPFLAGS="-I../include"
LDFLAGS="-lGLEW -lGLU -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl"
VENDIR="../src/vendor"

echo "Compiling..."
echo ""
echo "Cleaning old files..."
# Clean
rm -rf build/obj/*.o || echo "Error removing old object files in build/obj"
rm -rf src/*.o || echo "Error removing old object files in src"
echo "Done"
echo ""

# move into src/
cd src/

# VertexBuffer.h
# VertexArray.h
# IndexBuffer.h
# Shader.h
# Renderer.h
# stb_image.h
# Texture.h


# Compile
echo -e "\e[1;34mCompiling objects:\e[0m"
echo -e "\e[1;34m│\e[0m"

echo -e -n "\e[1;34m├ Compiling VertexBuffer...\e[0m"

g++ -c -o ${OBJ_DIR}/VertexBuffer.o  VertexBuffer.cpp 	${CPPFLAGS} ${LDFLAGS} && echo -e "\e[1;32mCompiled!\e[0m"

echo -e -n "\e[1;34m├ Compiling VertexArray...\e[0m"

g++ -c -o ${OBJ_DIR}/VertexArray.o   VertexArray.cpp  	${CPPFLAGS} ${LDFLAGS} && echo -e "\e[1;32mCompiled!\e[0m"

echo -e -n "\e[1;34m├ Compiling IndexBuffer...\e[0m"

g++ -c -o ${OBJ_DIR}/IndexBuffer.o   IndexBuffer.cpp  	${CPPFLAGS} ${LDFLAGS} && echo -e "\e[1;32mCompiled!\e[0m"

echo -e -n "\e[1;34m├ Compiling Shader...\e[0m"

g++ -c -o ${OBJ_DIR}/Shader.o        Shader.cpp       	${CPPFLAGS} ${LDFLAGS} && echo -e "\e[1;32mCompiled!\e[0m"

echo -e -n "\e[1;34m├ Compiling Renderer...\e[0m"

g++ -c -o ${OBJ_DIR}/Renderer.o      Renderer.cpp     	${CPPFLAGS} ${LDFLAGS} && echo -e "\e[1;32mCompiled!\e[0m"

echo -e -n "\e[1;34m├ Compiling stb_image...\e[0m"

g++ -c -o ${OBJ_DIR}/stb_image.o      ${VENDIR}/stb_image/stb_image.cpp     	${CPPFLAGS} ${LDFLAGS} && echo -e "\e[1;32mCompiled!\e[0m"

echo -e -n "\e[1;34m└ Compiling Texture...\e[0m"

g++ -c -o ${OBJ_DIR}/Texture.o      Texture.cpp     	${CPPFLAGS} ${LDFLAGS} && echo -e "\e[1;32mCompiled!\e[0m"




echo -e "\e[1;32mCompiled!\e[0m"
echo ""
echo -e "\e[1;36mLinking...\e[0m"
g++ -o ${BIN_DIR}/${PROGRAM_NAME} Application.cpp ${OBJ_FILES} ${CPPFLAGS} ${LDFLAGS} -I${VENDIR}/stb_image || echo "Error linking!"
echo -e "\e[1;32mCompiling complete!\e[0m"



cd ../build/bin/
echo -e -n "\e[1;36mChanging Permissions...\e[0m"
chmod +x ${PROGRAM_NAME} && sleep 0.5 && echo -e "\e[1;32m Changed!\e[0m"
echo ""

echo -e "\e[1;36mRunning...\e[0m"
echo ""
./${PROGRAM_NAME} 


