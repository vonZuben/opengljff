
#include"glShader.h"
#include"glWindow.h"

#include<iostream>

const char* srcvertex[] = {
    "#version 440 \n \
        in vec3 pos; \
        void main(){ \
           gl_Position = vec4(pos, 1.0);  \
        }"
};

const char* srcfragment[] = {
    "#version 440 \n \
        out vec4 color; \
        void main(){ \
            color = vec4(1.0, 1.0, 1.0, 1.0); \
        }"
};

using namespace particleSim;

enum renderShaderTypes{VERTEX, FRAGMET, NUMSHADERS};

int main (int argc, char** argv){

    glWindow* mainWindow = new glWindow(640, 480, "Particles", false);

    shadder renderPrgm;
    renderPrgm.createShaders(NUMSHADERS);
    renderPrgm.setShadderType(VERTEX, GL_VERTEX_SHADER);
    renderPrgm.setShadderType(FRAGMET, GL_FRAGMENT_SHADER);

    renderPrgm.addSource(VERTEX, srcvertex);
    renderPrgm.addSource(FRAGMET, srcfragment);

    renderPrgm.compileAll(NUMSHADERS);

    renderPrgm.bindFragData(0, "color");

    renderPrgm.link();

    while(!mainWindow->checkEvents()){
//
//        if (mainWindow->keyPressed(GLFW_KEY_A))
//            std::cout << "pressed" << '\n';

        mainWindow->updateWindow();
    }

    delete mainWindow;

    return 0;
}
