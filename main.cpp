
#include<cstdlib>

#include"glShader.h"
#include"glWindow.h"

#include"shaderSources.h"

#include<iostream>


using namespace particleSim;

//void mousePress(GLFWwindow *win, int button, int action, int mods){
//    (void) win;
//    (void) button;
//    (void) action;
//    (void) mods;
//
//    std::cout << "hello";
//}

enum renderShaderTypes{VERTEX, FRAGMET, NUMSHADERS};

int main (int argc, char** argv){

    glWindow* mainWindow = new glWindow(1000, 800, "Particles", false);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    shadder renderPrgm;
    renderPrgm.createShaders(NUMSHADERS);
    renderPrgm.setShadderType(VERTEX, GL_VERTEX_SHADER);
    renderPrgm.setShadderType(FRAGMET, GL_FRAGMENT_SHADER);

    renderPrgm.addSource(VERTEX, srcvertex);
    renderPrgm.addSource(FRAGMET, srcfragment);

    renderPrgm.compileAll(NUMSHADERS);

    renderPrgm.bindFragData(0, "color");

    renderPrgm.link();

    renderPrgm.usePrgm();

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    float *dat = new float[12000];

    srand(3);

    for (int i = 0; i < 12000; i++)
        dat[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    //float dat[] = { 0.0, 0.5, 0.0,
    //                0.5, 0.0, 0.0,
    //                0.5, 0.5, 0.0 };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*12000, dat, GL_STATIC_DRAW);

    delete[] dat;

    //GLint sPos = glGetAttribLocation(renderPrgm.getPrgm(), "position");
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    glViewport(-1000,-800,2000,1600);

    //glfwSetMouseButtonCallback(mainWindow->mainWindow, mousePress);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1.0f);

    while(!mainWindow->checkEvents()){
//
//        if (mainWindow->keyPressed(GLFW_KEY_A))
//            std::cout << "pressed" << '\n';

        glClearColor(0.0, 0.0, 0.0, 0.0);

        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_POINTS, 0, 4000);
        //glDrawArrays(GL_POINTS, 0, sizeof(dat)/(3*sizeof(float)));

        mainWindow->updateWindow();
    }

    glDeleteBuffers(1, &vao);
    glDeleteBuffers(1, &vbo);

    delete mainWindow;

    return 0;
}
