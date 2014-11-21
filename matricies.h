#ifndef MATRICIES_H
#define MATRICIES_H

#include<algorithm>

        // row major matricies for use with opengl and glm. transormations are done
        // for opengl which is column major therefor everything is inversed

class matm{

    private:

        int size;
        float* mat4;

    public:

        matm(int _size = 16) :
            size(_size),
            mat4(size ? new float[size] : 0)
            {}

        matm(const matm& other) :
            size(other.size),
            mat4(size ? new float[size] : 0)
            {
                std::copy(other.mat4, other.mat4 + size, mat4);
            }

        ~matm(){
            delete[] mat4;
        }

        matm& operator=(matm rhs);
        matm operator*(const matm& rhs) const;
        const matm& operator*=(const matm& rhs);

        void swap(matm& r, matm& l);

        void identity();

        void zero();

        void perspective(float fov, float aspectRatio, float near, float far);

        void xRotation(float angle);

        void yRotation(float angle);

        void zRotation(float angle);

        void translate(float x, float y, float z);

        float* val();
};

#endif
