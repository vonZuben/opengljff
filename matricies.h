#ifndef MATRICIES_H
#define MATRICIES_H

#include<glm/glm.hpp>

using namespace glm;
        // column major matricies for use with opengl and glm
class matm{

    private:

        mat4 mat;

    public:

        matm();

        ~matm();

        void identity();

        void xRotation(float angle);

        void yRotation(float angle);

};

#endif
