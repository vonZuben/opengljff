
#include<cstdlib>

#include"glShader.h"
#include"glWindow.h"

#include"shaderSources.h"

#include"matricies.h"

#include<iostream>

//#include<string.h>

#define PI 3.14159
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


using namespace particleSim;

int height, width;

void setView(float fovf){
    glm::mat4 worldView;
    //worldView = glm::perspective((float)PI*fovf, (float)width/height, 0.01f, 100.0f);

    matm perspective(true);
    matm temp;

    perspective.perspective((float)PI/2, (float)width/height, 0.01f, 100.0f);

    glm::vec3 pos = glm::vec3(2.0, 0.0, 0.0);
    worldView = glm::lookAt(pos, pos + glm::vec3(-1.0,0, 0), glm::vec3(0.0, 0.0, 1.0));

    //GLuint worldViewLoc = glGetAttribLocation(//prgm, //name);
    glUniformMatrix4fv(2, 1, GL_FALSE, perspective.val());
    //glUniformMatrix4fv(4, 1, GL_FALSE, temp.val());
    glUniformMatrix4fv(4, 1, GL_FALSE, &worldView[0][0]);
}

void sizeChange(GLFWwindow *win, int x, int y){
    //setView(0.5, 0.0, x, y);
    width = x;
    height = y;
    glViewport(0,0,x,y);
    setView(0.5);
}

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

    width = 1000;
    height = 800;

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

    float *dat = new float[15000];

    srand(3);

    for (int i = 0; i < 15000; i++)
        dat[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    //float dat[] = { 0.0, 0.5, 0.0,
    //                0.5, 0.0, 0.0,
    //                0.5, 0.5, 0.0 };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*15000, dat, GL_STATIC_DRAW);

    delete[] dat;

    GLuint indirectData[4];
    indirectData[0] = 5000;
    indirectData[1] = 1;
    indirectData[2] = 1;
    indirectData[3] = 0;

    GLuint indirectBuf;
    glGenBuffers(1, &indirectBuf);
    glBindBuffer(GL_DRAW_INDIRECT_BUFFER, indirectBuf);
    glBufferData(GL_DRAW_INDIRECT_BUFFER, sizeof(GLuint) * 4, indirectData, GL_STATIC_DRAW);

    //GLint sPos = glGetAttribLocation(renderPrgm.getPrgm(), "position");
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    //glfwSetMouseButtonCallback(mainWindow->mainWindow, mousePress);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_POINT_SMOOTH);
    glPointSize(1.0f);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    //float camerpos = 1.0f;
    setView(0.5);

    glfwSetWindowSizeCallback(mainWindow->mainWindow, sizeChange);

    double mx, my;
    double omx, omy;
    double dx, dy;

//    glm::mat4 rotTMP;
//
//    memset(&rotTMP[0][0], 0, 16 * sizeof(float));
//
//    rotTMP[0][0] = 1;
//    rotTMP[1][1] = 1;
//    rotTMP[2][2] = 1;
//    rotTMP[3][3] = 1;

    //glUniformMatrix4fv(3, 1, GL_FALSE, &rotTMP[0][0]);

    matm transform(true);

    //transform.xRotation(PI/2);

    //transform.xRotation(1.3);
    //transform.zRotation(PI/2);
    transform.translate(-0.5, -0.5, -0.5);

    glUniformMatrix4fv(3, 1, GL_FALSE, transform.val());

    while(!mainWindow->checkEvents()){

        if (glfwGetKey(mainWindow->mainWindow, GLFW_KEY_ESCAPE))
                break;

        if (glfwGetMouseButton(mainWindow->mainWindow, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
        {
            glfwGetCursorPos(mainWindow->mainWindow, &mx, &my);
            dx = mx - omx;
            dy = my - omy;

            omx = mx;
            omy = my;

            transform.yRotation(dy/100);
            transform.zRotation(dx/100);
            glUniformMatrix4fv(3, 1, GL_FALSE, transform.val());
        }
        else
        {
            glfwGetCursorPos(mainWindow->mainWindow, &omx, &omy);
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //glDrawArrays(GL_POINTS, 0, 4000);
        glDrawArraysIndirect(GL_POINTS, 0);
        //glDrawArrays(GL_POINTS, 0, sizeof(dat)/(3*sizeof(float)));

        mainWindow->updateWindow();
    }

    glDeleteBuffers(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &indirectBuf);

    delete mainWindow;

    return 0;
}
