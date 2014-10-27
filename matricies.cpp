#include"matricies.h"

#include<math.h>
#include<string.h>

using namespace std;

matm::matm(){
    memset(mat, 0, 16*sizeof(float));
    identity();
}

matm::matm(bool loadIdentity){
    memset(mat, 0, 16*sizeof(float));
    if (loadIdentity) identity();
}

matm::~matm(){
    //delete[] mat;
}

void matm::identity(){
    mat[0][0] = 1;
    mat[1][1] = 1;
    mat[2][2] = 1;
    mat[3][3] = 1;
}

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

float* matm::val(){
    return &mat[0][0];
}

const matm& matm::operator=(const matm& rhs){

    memcpy(this->mat, rhs.mat, 16*sizeof(float));

    return *this;
}

matm matm::operator*(const matm& rhs) const{

    matm t(false);

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            for (int inner = 0; inner < 4; inner++) {
                t.mat[row][col] += this->mat[row][inner] * rhs.mat[inner][col];
            }
        }
    }

    return t;
}

const matm& matm::operator*=(const matm& rhs){

    *this = *this * rhs;

    return *this;
}
