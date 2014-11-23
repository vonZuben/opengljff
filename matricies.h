#ifndef MATRICIES_H
#define MATRICIES_H

#include<algorithm>

        // row major matricies for use with opengl and glm. transormations are done
        // for opengl which is column major therefor everything is inversed

class matm{

    private:

        int size; // i figure this makes it more general just in case
        float* mat;

    public:

        matm(int _size = 16) :
            size(_size),
            mat(size ? new float[size] : 0)
            {}

        matm(const matm& other) :
            size(other.size),
            mat(size ? new float[size] : 0)
            {
                std::copy(other.mat, other.mat + size, mat);
            }

        matm(matm&& other) : matm(0)
        {
            swap(*this, other);
        }

        ~matm(){
            delete[] mat;
        }

        matm& operator=(const matm& rhs);
        matm& operator=(matm&& rhs);
        matm operator*(const matm& rhs) const;
        const matm& operator*=(const matm& rhs);


        void identity();

        void zero();

        void perspective(float fov, float aspectRatio, float near, float far);

        void xRotation(float angle);

        void yRotation(float angle);

        void zRotation(float angle);

        void translate(float x, float y, float z);

        float* val();

        friend void swap(matm& r, matm& l);
};

#endif
