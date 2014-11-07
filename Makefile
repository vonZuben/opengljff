FIELS=*.cpp

LPATH=-L/home/chris/gl/particles
LIBS=-lGL -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lXi -lpthread -lXcursor -lXinerama

CFLAGS=-Wall -O0 -g

default:
	g++ -o program $(FIELS) $(CFLAGS) $(LPATH) $(LIBS)
run:
	./program
