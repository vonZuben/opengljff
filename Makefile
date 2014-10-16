all:
	g++ -o program -lglfw -lGLEW -lGL glWindow.cpp main.cpp glShader.cpp matricies.cpp -g -Wall -O0

run:
	./program
