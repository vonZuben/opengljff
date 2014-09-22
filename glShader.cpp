

#include "glShader.h"

void shadder::createShaders(int num){
    shadder::shader = new GLuint[num];
}

void shadder::setShadderType(int index, GLenum type){
    shadder::shader[index] = glCreateShader(type);
}

void shadder::addSource(int index, char **src){
    glShaderSource(shadder::shader[index], 1, src, NULL);
}
