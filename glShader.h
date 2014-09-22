#ifndef GLSHADER_H
#define GLSHADER_H

#define GLEW_STATIC
#include <GL/glew.h>

class shadder{

    private:
        GLuint *shader;
        GLuint prgm;

    public:

        void createShaders(int num);

        void setShadderType(int index, GLenum type);

        void addSource(int index, char **src);

};

#endif
