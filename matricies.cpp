#include"matricies.h"

#include<math.h>
#include<string.h>

using namespace std;

matm::matm(){
    //mat = new float[16];
    identity();
}

matm::~matm(){
    //delete[] mat;
}

void matm::identity(){
    memset(mat, 0, 16*sizeof(float));
    mat[0][0] = 1;
    mat[1][1] = 1;
    mat[2][2] = 1;
    mat[3][3] = 1;
}

void matm::xRotation(float angle){

    float rotation[4][4] = {
        1, 0, 0, 0,
        0, (float)cos((double)angle), -(float)sin((double)angle), 0,
        0, (float)sin((double)angle), (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    matm t;
    memcpy(t.val(), rotation, 16*sizeof(float));

    *this *= t;
}

void matm::yRotation(float angle){
    
    float rotation[4][4] = {
        (float)cos((double)angle), 0, (float)sin((double)angle), 0,
        0, 1, 0, 0,
        -(float)sin((double)angle), 0, (float)cos((double)angle), 0,
        0, 0, 0, 1
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

    matm t;

    // row 1

    t.mat[0][0] = (this->mat[0][0] * rhs.mat[0][0]) + (this->mat[0][1] * rhs.mat[1][0])
        + (this->mat[0][2] * rhs.mat[2][0]) + (this->mat[0][3] * rhs.mat[3][0]);

    t.mat[0][1] = (this->mat[0][0] * rhs.mat[0][1]) + (this->mat[0][1] * rhs.mat[1][1])
        + (this->mat[0][2] * rhs.mat[2][1]) + (this->mat[0][3] * rhs.mat[3][1]);

    t.mat[0][2] = (this->mat[0][0] * rhs.mat[0][2]) + (this->mat[0][1] * rhs.mat[1][2])
        + (this->mat[0][2] * rhs.mat[2][2]) + (this->mat[0][3] * rhs.mat[3][2]);

    t.mat[0][3] = (this->mat[0][0] * rhs.mat[0][3]) + (this->mat[0][1] * rhs.mat[1][3])
        + (this->mat[0][2] * rhs.mat[2][3]) + (this->mat[0][3] * rhs.mat[3][3]);

    // row 2

    t.mat[1][0] = (this->mat[1][0] * rhs.mat[0][0]) + (this->mat[1][1] * rhs.mat[1][0])
        + (this->mat[1][2] * rhs.mat[2][0]) + (this->mat[1][3] * rhs.mat[3][0]);

    t.mat[1][1] = (this->mat[1][0] * rhs.mat[0][1]) + (this->mat[1][1] * rhs.mat[1][1])
        + (this->mat[1][2] * rhs.mat[2][1]) + (this->mat[1][3] * rhs.mat[3][1]);

    t.mat[1][2] = (this->mat[1][0] * rhs.mat[0][2]) + (this->mat[1][1] * rhs.mat[1][2])
        + (this->mat[1][2] * rhs.mat[2][2]) + (this->mat[1][3] * rhs.mat[3][2]);

    t.mat[1][3] = (this->mat[1][0] * rhs.mat[0][3]) + (this->mat[1][1] * rhs.mat[1][3])
        + (this->mat[1][2] * rhs.mat[2][3]) + (this->mat[1][3] * rhs.mat[3][3]);

    // row 3

    t.mat[2][0] = (this->mat[2][0] * rhs.mat[0][0]) + (this->mat[2][1] * rhs.mat[2][0])
        + (this->mat[2][2] * rhs.mat[2][0]) + (this->mat[2][3] * rhs.mat[3][0]);

    t.mat[2][1] = (this->mat[2][0] * rhs.mat[0][1]) + (this->mat[2][1] * rhs.mat[1][1])
        + (this->mat[2][2] * rhs.mat[2][1]) + (this->mat[2][3] * rhs.mat[3][1]);

    t.mat[2][2] = (this->mat[2][0] * rhs.mat[0][2]) + (this->mat[2][1] * rhs.mat[1][2])
        + (this->mat[2][2] * rhs.mat[2][2]) + (this->mat[2][3] * rhs.mat[3][2]);

    t.mat[2][3] = (this->mat[2][0] * rhs.mat[0][3]) + (this->mat[2][1] * rhs.mat[1][3])
        + (this->mat[2][2] * rhs.mat[2][3]) + (this->mat[2][3] * rhs.mat[3][3]);

    // row 3

    t.mat[3][0] = (this->mat[3][0] * rhs.mat[0][0]) + (this->mat[3][1] * rhs.mat[2][0])
        + (this->mat[3][2] * rhs.mat[2][0]) + (this->mat[3][3] * rhs.mat[3][0]);

    t.mat[3][1] = (this->mat[3][0] * rhs.mat[0][1]) + (this->mat[3][1] * rhs.mat[1][1])
        + (this->mat[3][2] * rhs.mat[2][1]) + (this->mat[3][3] * rhs.mat[3][1]);

    t.mat[3][2] = (this->mat[3][0] * rhs.mat[0][2]) + (this->mat[3][1] * rhs.mat[1][2])
        + (this->mat[3][2] * rhs.mat[2][2]) + (this->mat[3][3] * rhs.mat[3][2]);

    t.mat[3][3] = (this->mat[3][0] * rhs.mat[0][3]) + (this->mat[3][1] * rhs.mat[1][3])
        + (this->mat[3][2] * rhs.mat[2][3]) + (this->mat[3][3] * rhs.mat[3][3]);

    return t;
}

const matm& matm::operator*=(const matm& rhs){

    *this = *this * rhs;

    return *this;
}
