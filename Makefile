all:
	g++ -o program -lglfw glWindow.cpp main.cpp

run:
	./program
