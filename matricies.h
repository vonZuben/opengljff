#ifndef MATRICIES_H
#define MATRICIES_H

#include<algorithm>
#include<initializer_list>

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

        matm(matm&& other) : matm(0) {
            swap(*this, other);
        }

        matm(std::initializer_list<float> l) : matm(l.size()) {
            float* tmp = mat;
            for (float i : l)
                *tmp++ = i;
        }

        ~matm(){
            delete[] mat;
        }

        friend void swap(matm& r, matm& l);

        matm& operator=(const matm& rhs);
        matm& operator=(matm&& rhs);
        matm operator*(const matm& rhs) const;
        const matm& operator*=(const matm& rhs);
        const float* operator*()const;


        void identity();

        void zero();

        };

#endif
