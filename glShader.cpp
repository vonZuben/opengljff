
#include<iostream>
#include "glShader.h"

void shadder::createShaders(int num){
    shadder::shader = new GLuint[num];
}

void shadder::setShadderType(int index, GLenum type){
    shadder::shader[index] = glCreateShader(type);
}

void shadder::addSource(int index, const char **src){
    glShaderSource(shadder::shader[index], 1, src, NULL);
}

void shadder::compileAll(int num){
    GLuint sprgm = glCreateProgram();

    for (int i = 0; i < num; i++){
        glCompileShader(shadder::shader[i]);
        int rv;
        glGetShaderiv(shadder::shader[i], GL_COMPILE_STATUS, &rv);
        char log[4096];
        glGetShaderInfoLog(shadder::shader[i], 4096, NULL, log);
        std::cout << log << '\n';

        glAttachShader(sprgm, shadder::shader[i]);
    }

}
        
void shadder::bindFragData(GLuint colorNumber, const char *data){
    glBindFragDataLocation(shadder::prgm, colorNumber, data);
}

void shadder::link(){
    glLinkProgram(shadder::prgm);
    int rv;
    char log[4096];
    glGetProgramiv(shadder::prgm, GL_LINK_STATUS, &rv);
    glGetProgramInfoLog(shadder::prgm, 4096, NULL, log);
    std::cout << log << '\n';
}
