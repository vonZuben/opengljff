
#include"glWindow.h"

using namespace particleSim;

int main (int argc, char** argv){

    glWindow* mainWindow = new glWindow(640, 480, "Hello World", false);

    //mainWindow.createWindow(640, 480, "Hello World", false);

    while(!mainWindow->checkEvents()){

        mainWindow->updateWindow();
    }

    delete mainWindow;

    return 0;
}
