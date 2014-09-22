#ifndef WINDOW_H
#define WINDOW_H

//this class should be treated as the main class that must be used to create the main gl context

#define MAX_KEYS_DOWN 10

#include<GLFW/glfw3.h>

namespace particleSim{

    class glWindow{

        private:
            GLFWwindow* mainWindow;
            static bool isInitialized;
            int inArray(int *array, int length, int val);

        public:
            static int hello;

            void createWindow(int width, int height, const char* name, bool fullScreen);

            bool checkEvents();

            void updateWindow();

            bool keyPressed(int key);

            glWindow();
            glWindow(int width, int height, const char* name, bool fullScreen);
            ~glWindow();
    };
};

#endif
