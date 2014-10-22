#include"matricies.h"

#include<math.h>
#include<string.h>

using namespace std;

matm::matm(){
    mat = new float[16];
    identity();
}

matm::~matm(){
    delete[] mat;
}

void matm::identity(){
    memset(mat, 0, 16*sizeof(float));
    mat[0] = 1;
    mat[5] = 1;
    mat[10] = 1;
    mat[15] = 1;
}

void matm::xRotation(float angle){

    float rotation[] = {
        1, 0, 0, 0,
        0, (float)cos((double)angle), -(float)sin((double)angle), 0,
        0, (float)sin((double)angle), (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    (void)rotation;
    
}

void matm::yRotation(float angle){

}

float* matm::val(){
    return mat;
}
