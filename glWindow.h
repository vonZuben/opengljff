#ifndef WINDOW_H
#define WINDOW_H

#include<GLFW/glfw3.h>

namespace particleSim{

    class glWindow{

        private:
            GLFWwindow* mainWindow;

        public:

            void createWindow(int width, int height, const char* name, bool fullScreen);

            bool checkEvents();

            void updateWindow();

            glWindow();
            glWindow(int width, int height, const char* name, bool fullScreen);
            ~glWindow();
    };
};

#endif
