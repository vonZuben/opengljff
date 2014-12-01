GCC=
FIELS=*.cpp

LPATH=-L$(PWD)
LIBS=-lGL -lGLEW -lGLUS -lglfw3 -lX11 -lXxf86vm -lXrandr -lXi -lpthread -lXcursor -lXinerama

CFLAGS=-Wall -O0 -g -std=c++11

PRGM=program

DEFIENS=-D GLUS

default:
	g++ -o $(PRGM) $(FIELS) $(CFLAGS) $(LPATH) $(LIBS) $(DEFIENS)
run:
	./$(PRGM)
