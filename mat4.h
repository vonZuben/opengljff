#ifndef MAT4_H
#define MAT4_H

#include"matricies.h"

class glmat4{

private:

    matm mat4;


public:

    glmat4(){
        mat4 = matm(16);
    }

    void perspective(float fov, float aspectRatio, float near, float far);

    void xRotation(float angle);

    void yRotation(float angle);

    void zRotation(float angle);

    void translate(float x, float y, float z);

    void scale(float xs, float ys, float zs);

    void identity();

    operator const float*()const;
};

#endif
