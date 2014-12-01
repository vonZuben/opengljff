#include"matricies.h"

#include<cmath>
#include<utility>
#include<algorithm>


void swap(matm& r, matm& l){
    std::swap(r.size, l.size);
    std::swap(r.mat, l.mat);
}

void matm::identity(){ // should only be used on matrices that are thought of as square
    zero();
    for (int i = 0; i < size; i += std::sqrt(size) + 1)
        mat[i] = 1;
}

void matm::zero(){
    std::fill(&mat[0], &mat[size], 0);
}

const float* matm::operator*()const{
    return mat;
}

matm& matm::operator=(const matm& rhs){
    matm tmp(rhs); // I do this so that I can have sudo copy swap assignment operator and move assignment
    swap(*this, tmp);
    return *this;
}

matm& matm::operator=(matm&& rhs){ // lets me avoid creating a copy for no reason
    swap(*this, rhs);
    return *this;
}

matm matm::operator*(const matm& rhs) const{

    matm t;
    t.zero();

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            for (int inner = 0; inner < 4; inner++) {
                t.mat[4 * row + col] += this->mat[4 * row + inner] * rhs.mat[4 * inner + col];
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

    matm t = {
        1/(aspectRatio*(float)tan(fov/2)), 0, 0, 0,
        0, 1/(float)tan(fov/2), 0, 0,
        0, 0, -((far + near)/(far - near)), -1,
        0, 0, -((2*far*near)/(far - near)), 0
    };

    *this *= t;
}

void matm::xRotation(float angle){

    matm t = {
        1, 0, 0, 0,
        0, (float)cos((double)angle), (float)sin((double)angle), 0,
        0, -(float)sin((double)angle), (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    *this *= t;
}

void matm::yRotation(float angle){

    matm t = {
        (float)cos((double)angle), 0, -(float)sin((double)angle), 0,
        0, 1, 0, 0,
        (float)sin((double)angle), 0, (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    *this *= t;
}

void matm::zRotation(float angle){

    matm t = {
        (float)cos((double)angle), (float)sin((double)angle), 0, 0,
        -(float)sin((double)angle), (float)cos((double)angle), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    *this *= t;
}

void matm::translate(float x, float y, float z){

    matm t = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        x, y, z, 1
    };

    *this *= t;
}

void matm::scale(float xs, float ys, float zs){
    matm t = {
        xs, 0, 0, 0,
        0, ys, 0, 0,
        0, 0, zs, 0,
        0, 0, 0, 1
    };

    *this *= t;
}
