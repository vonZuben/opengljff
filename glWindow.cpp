#define GLEW_STATIC
#include<GL/glew.h>

#include"glWindow.h"

#include<GLFW/glfw3.h>


using namespace particleSim;

void glWindow::createWindow(int width, int height, const char* name, bool fullScreen){
    mainWindow = glfwCreateWindow(width, height, name,
            fullScreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    glfwMakeContextCurrent(mainWindow);
}

bool glWindow::checkEvents(){
    glfwPollEvents();
    return glfwWindowShouldClose(mainWindow);
}

void glWindow::updateWindow(){
    glfwSwapBuffers(mainWindow);
}

glWindow::glWindow(){
    glfwInit();
}

glWindow::glWindow(int width, int height, const char* name, bool fullScreen){
    glfwInit();
    mainWindow = glfwCreateWindow(width, height, name,
            fullScreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    glfwMakeContextCurrent(mainWindow);
}

glWindow::~glWindow(){
    glfwTerminate();
}
