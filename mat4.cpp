#include "mat4.h"

#include<cmath>
#include<utility>
#include<algorithm>

void glmat4::identity(){
    mat4.identity();
}

void glmat4::perspective(float fov, float aspectRatio, float near, float far){

    matm t = {
        1/(aspectRatio*(float)tan(fov/2)), 0, 0, 0,
        0, 1/(float)tan(fov/2), 0, 0,
        0, 0, -((far + near)/(far - near)), -1,
        0, 0, -((2*far*near)/(far - near)), 0
    };

    mat4 *= t;
}

void glmat4::xRotation(float angle){

    matm t = {
        1, 0, 0, 0,
        0, (float)cos((double)angle), (float)sin((double)angle), 0,
        0, -(float)sin((double)angle), (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    mat4 *= t;
}

void glmat4::yRotation(float angle){

    matm t = {
        (float)cos((double)angle), 0, -(float)sin((double)angle), 0,
        0, 1, 0, 0,
        (float)sin((double)angle), 0, (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    mat4 *= t;
}

void glmat4::zRotation(float angle){

    matm t = {
        (float)cos((double)angle), (float)sin((double)angle), 0, 0,
        -(float)sin((double)angle), (float)cos((double)angle), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    mat4 *= t;
}

void glmat4::translate(float x, float y, float z){

    matm t = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        x, y, z, 1
    };

    mat4 *= t;
}

void glmat4::scale(float xs, float ys, float zs){
    matm t = {
        xs, 0, 0, 0,
        0, ys, 0, 0,
        0, 0, zs, 0,
        0, 0, 0, 1
    };

    mat4 *= t;
}

glmat4::operator const float*()const{
    return *mat4;
}
