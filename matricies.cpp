#include"matricies.h"

#include<cmath>
#include<cstring>
#include<iostream>
#include<utility>
#include<algorithm>


void matm::swap(matm& r, matm& l){
    std::swap(r.size, l.size);
    std::swap(r.mat4, l.mat4);
}

void matm::identity(){
    zero();
    mat4[0] = 1;
    mat4[5] = 1;
    mat4[10] = 1;
    mat4[15] = 1;
}

void matm::zero(){
    std::fill(&mat4[0], &mat4[size], 0);
}


float* matm::val(){
    return mat4;
}

matm& matm::operator=(matm rhs){

    swap(*this, rhs);

    return *this;
}

matm matm::operator*(const matm& rhs) const{

    matm t;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            for (int inner = 0; inner < 4; inner++) {
                t.mat4[4 * row + col] += this->mat4[4 * row + inner] * rhs.mat4[4 * inner + col];
            }
        }
    }

    return t;
}

const matm& matm::operator*=(const matm& rhs){

    *this = *this * rhs;

    return *this;
}

// the following functions are for 4 x 4 matricise only

void matm::perspective(float fov, float aspectRatio, float near, float far){

    float rotation[4][4] = {
        1/(aspectRatio*(float)tan(fov/2)), 0, 0, 0,
        0, 1/(float)tan(fov/2), 0, 0,
        0, 0, -((far + near)/(far - near)), -1,
        0, 0, -((2*far*near)/(far - near)), 0
    };

    matm t;
    memcpy(t.val(), rotation, 16*sizeof(float));

    *this *= t;
}

void matm::xRotation(float angle){

    float rotation[4][4] = {
        1, 0, 0, 0,
        0, (float)cos((double)angle), (float)sin((double)angle), 0,
        0, -(float)sin((double)angle), (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    matm t;
    memcpy(t.val(), rotation, 16*sizeof(float));

    *this *= t;
}

void matm::yRotation(float angle){

    float rotation[4][4] = {
        (float)cos((double)angle), 0, -(float)sin((double)angle), 0,
        0, 1, 0, 0,
        (float)sin((double)angle), 0, (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    matm t;
    memcpy(t.val(), rotation, 16*sizeof(float));

    *this *= t;
}

void matm::zRotation(float angle){

    float rotation[4][4] = {
        (float)cos((double)angle), (float)sin((double)angle), 0, 0,
        -(float)sin((double)angle), (float)cos((double)angle), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    matm t;
    memcpy(t.val(), rotation, 16*sizeof(float));

    *this *= t;
}

void matm::translate(float x, float y, float z){

    float rotation[4][4] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        x, y, z, 1
    };

    matm t;
    memcpy(t.val(), rotation, 16*sizeof(float));

    *this *= t;
}

