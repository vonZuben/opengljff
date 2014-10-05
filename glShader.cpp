
#include<iostream>
#include "glShader.h"

shadder::~shadder(){
    glDeleteProgram(shadder::prgm);
    for (int i = 0; i < shadder::numShadders; i++)
        glDeleteShader(shadder::shader[i]);

    delete[] shadder::shader;
}

void shadder::createShaders(int num){
    shadder::shader = new GLuint[num];
    shadder::numShadders = num;
}

void shadder::setShadderType(int index, GLenum type){
    shadder::shader[index] = glCreateShader(type);
}

void shadder::addSource(int index, const char **src){
    glShaderSource(shadder::shader[index], 1, src, NULL);
}

void shadder::compileAll(int num){
    shadder::prgm = glCreateProgram();

    for (int i = 0; i < num; i++){
        glCompileShader(shadder::shader[i]);
        int rv;
        glGetShaderiv(shadder::shader[i], GL_COMPILE_STATUS, &rv);
        char log[4096];
        glGetShaderInfoLog(shadder::shader[i], 4096, NULL, log);
        std::cout << log << '\n';

        glAttachShader(shadder::prgm, shadder::shader[i]);
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

void shadder::usePrgm(){
    glUseProgram(shadder::prgm);
}

GLuint shadder::getPrgm() const{
    return shadder::prgm;
}
