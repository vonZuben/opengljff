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
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 4; inner++) {
                t.mat[row][col] += this->mat[row][inner] * rhs.mat[inner][col];
            }
        }
    }

//    // row 1
//
//    t.mat[0][0] = (this->mat[0][0] * rhs.mat[0][0]) + (this->mat[0][1] * rhs.mat[1][0])
//        + (this->mat[0][2] * rhs.mat[2][0]) + (this->mat[0][3] * rhs.mat[3][0]);
//
//    t.mat[0][1] = (this->mat[0][0] * rhs.mat[0][1]) + (this->mat[0][1] * rhs.mat[1][1])
//        + (this->mat[0][2] * rhs.mat[2][1]) + (this->mat[0][3] * rhs.mat[3][1]);
//
//    t.mat[0][2] = (this->mat[0][0] * rhs.mat[0][2]) + (this->mat[0][1] * rhs.mat[1][2])
//        + (this->mat[0][2] * rhs.mat[2][2]) + (this->mat[0][3] * rhs.mat[3][2]);
//
//    t.mat[0][3] = (this->mat[0][0] * rhs.mat[0][3]) + (this->mat[0][1] * rhs.mat[1][3])
//        + (this->mat[0][2] * rhs.mat[2][3]) + (this->mat[0][3] * rhs.mat[3][3]);
//
//    // row 2
//
//    t.mat[1][0] = (this->mat[1][0] * rhs.mat[0][0]) + (this->mat[1][1] * rhs.mat[1][0])
//        + (this->mat[1][2] * rhs.mat[2][0]) + (this->mat[1][3] * rhs.mat[3][0]);
//
//    t.mat[1][1] = (this->mat[1][0] * rhs.mat[0][1]) + (this->mat[1][1] * rhs.mat[1][1])
//        + (this->mat[1][2] * rhs.mat[2][1]) + (this->mat[1][3] * rhs.mat[3][1]);
//
//    t.mat[1][2] = (this->mat[1][0] * rhs.mat[0][2]) + (this->mat[1][1] * rhs.mat[1][2])
//        + (this->mat[1][2] * rhs.mat[2][2]) + (this->mat[1][3] * rhs.mat[3][2]);
//
//    t.mat[1][3] = (this->mat[1][0] * rhs.mat[0][3]) + (this->mat[1][1] * rhs.mat[1][3])
//        + (this->mat[1][2] * rhs.mat[2][3]) + (this->mat[1][3] * rhs.mat[3][3]);
//
//    // row 3
//
//    t.mat[2][0] = (this->mat[2][0] * rhs.mat[0][0]) + (this->mat[2][1] * rhs.mat[2][0])
//        + (this->mat[2][2] * rhs.mat[2][0]) + (this->mat[2][3] * rhs.mat[3][0]);
//
//    t.mat[2][1] = (this->mat[2][0] * rhs.mat[0][1]) + (this->mat[2][1] * rhs.mat[1][1])
//        + (this->mat[2][2] * rhs.mat[2][1]) + (this->mat[2][3] * rhs.mat[3][1]);
//
//    t.mat[2][2] = (this->mat[2][0] * rhs.mat[0][2]) + (this->mat[2][1] * rhs.mat[1][2])
//        + (this->mat[2][2] * rhs.mat[2][2]) + (this->mat[2][3] * rhs.mat[3][2]);
//
//    t.mat[2][3] = (this->mat[2][0] * rhs.mat[0][3]) + (this->mat[2][1] * rhs.mat[1][3])
//        + (this->mat[2][2] * rhs.mat[2][3]) + (this->mat[2][3] * rhs.mat[3][3]);
//
//    // row 3
//
//    t.mat[3][0] = (this->mat[3][0] * rhs.mat[0][0]) + (this->mat[3][1] * rhs.mat[2][0])
//        + (this->mat[3][2] * rhs.mat[2][0]) + (this->mat[3][3] * rhs.mat[3][0]);
//
//    t.mat[3][1] = (this->mat[3][0] * rhs.mat[0][1]) + (this->mat[3][1] * rhs.mat[1][1])
//        + (this->mat[3][2] * rhs.mat[2][1]) + (this->mat[3][3] * rhs.mat[3][1]);
//
//    t.mat[3][2] = (this->mat[3][0] * rhs.mat[0][2]) + (this->mat[3][1] * rhs.mat[1][2])
//        + (this->mat[3][2] * rhs.mat[2][2]) + (this->mat[3][3] * rhs.mat[3][2]);
//
//    t.mat[3][3] = (this->mat[3][0] * rhs.mat[0][3]) + (this->mat[3][1] * rhs.mat[1][3])
//        + (this->mat[3][2] * rhs.mat[2][3]) + (this->mat[3][3] * rhs.mat[3][3]);
//
    return t;
}

const matm& matm::operator*=(const matm& rhs){

    *this = *this * rhs;

    return *this;
}
