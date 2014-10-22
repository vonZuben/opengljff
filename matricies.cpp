#include"matricies.h"

#include<math.h>
#include<string.h>

using namespace std;

matm::matm(){
    identity();
}

matm::~matm(){
}

void matm::identity(){
    mat[0][0] = 1;
    mat[1][1] = 1;
    mat[2][2] = 1;
    mat[3][3] = 1;
}

void matm::xRotation(float angle){

    float rotation[] = {
        1, 0, 0, 0,
        0, (float)cos((double)angle), -(float)sin((double)angle), 0,
        0, (float)sin((double)angle), (float)cos((double)angle), 0,
        0, 0, 0, 1
    };

    mat4 tmp;

    memcpy(&tmp[0][0], &rotation, 16);

    matm::mat *= tmp;
}

void matm::yRotation(float angle){

}
