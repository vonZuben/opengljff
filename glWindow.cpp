#define GLEW_STATIC
#include<GL/glew.h>

#include"glWindow.h"

#include<GLFW/glfw3.h>


using namespace particleSim;

bool glWindow::isInitialized = false;

void glWindow::createWindow(int width, int height, const char* name, bool fullScreen){
    mainWindow = glfwCreateWindow(width, height, name,
            fullScreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    glfwMakeContextCurrent(mainWindow);

    glewInit();
}

bool glWindow::checkEvents(){
    glfwPollEvents();
    return glfwWindowShouldClose(mainWindow);
}

void glWindow::updateWindow(){
    glfwSwapBuffers(mainWindow);
}

bool glWindow::keyPressed(int key){
   // int keyState;
   // int indexO, indexN;

   // static int oldKeys[MAX_KEYS_DOWN];
   // static int curKeys[MAX_KEYS_DOWN];

   // keyState = glfwGetKey(glWindow::mainWindow, key);

   // indexO = glWindow::inArray(oldKeys, MAX_KEYS_DOWN, key);
   // indexN = glWindow::inArray(curKeys, MAX_KEYS_DOWN, key);

   // if (indexN < 0 && keyState == GLFW_PRESS){
   //     indexN = glWindow::inArray(curKeys, MAX_KEYS_DOWN, 0);
   //     curKeys[indexN] = key;
   //     return true;
   // }
   // else if (indexO < 0){
   //     indexO = glWindow::inArray(oldKeys, MAX_KEYS_DOWN, 0);
   //     oldKeys[indexO] = curKeys[indexN];
   // }

   // if (keyState == GLFW_PRESS){
   //     if (indexO < 0
   // }
   // else{
   //     return false;
   // }
   return false;
}

int glWindow::inArray(int *array, int length, int val){
    for (int i = 0; i < length; i++)
        if (array[i] == val)
            return i;
    return -1;
}

glWindow::glWindow(){
    if (!glWindow::isInitialized)
        glfwInit();
}

glWindow::glWindow(int width, int height, const char* name, bool fullScreen){
    if (!glWindow::isInitialized)
        glfwInit();
    mainWindow = glfwCreateWindow(width, height, name,
            fullScreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    glfwMakeContextCurrent(mainWindow);

    glewInit();
}

glWindow::~glWindow(){
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
}
