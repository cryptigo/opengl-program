PROGRAM_NAME:=OpenGL_Program

INCLUDE_PATH=lib/

RM=rm -f

SOURCE_FILES := src/main.cpp
OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))

BIN_DIR=build/bin/
OBJ_DIR=build/obj/

CC:=g++
CPPFLAGS := -std=c++11 -Wall -g
LIBFLAGS := -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl

main: $(CC) $(CPPFLAGS) -o $(PROGRAM_NAME) $(LIBFLAGS)
