GCC=
FIELS=*.cpp

LPATH=-L$(PWD)
LIBS=-lGL -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lXi -lpthread -lXcursor -lXinerama

CFLAGS=-O0 -std=c++11 -Wall -g 

PRGM=program

DEFIENS=-D GLUS

default:
	g++ -o $(PRGM) $(FIELS) $(CFLAGS) $(LPATH) $(LIBS) $(DEFIENS)
run:
	./$(PRGM)
