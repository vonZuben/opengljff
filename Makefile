all:
	g++ -o program -lglfw -lGLEW glWindow.cpp main.cpp glShader.cpp -g -Wall -O0

run:
	./program
