GPP=
FIELS=*.cpp

LPATH=-L$(PWD)
LIBS=-lGL -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lXi -lpthread -lXcursor -lXinerama

CFLAGS=-Wall -O0 -g

PRGM=program

default:
	g++ -o $(PRGM) $(FIELS) $(CFLAGS) $(LPATH) $(LIBS)
run:
	./$(PRGM)
