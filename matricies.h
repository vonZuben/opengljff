#ifndef MATRICIES_H
#define MATRICIES_H

#include<algorithm>
#include<initializer_list>

        // row major matricies for use with opengl and glm. transormations are done
        // for opengl which is column major therefor everything is inversed

template<typename T = float>
class matm{

    private:

        int size; // i figure this makes it more general just in case
        T* mat;

    public:

        matm(int _size = 16) :
            size(_size),
            mat(size ? new T[size] : 0)
            {}

        matm(const matm& other) :
            size(other.size),
            mat(size ? new T[size] : 0)
            {
                std::copy(other.mat, other.mat + size, mat);
            }

        matm(matm&& other) : matm(0) {
            swap(*this, other);
        }

        matm(std::initializer_list<T> l) : matm(l.size()) {
            T* tmp = mat;
            for (T i : l)
                *tmp++ = i;
        }

        ~matm(){
            delete[] mat;
        }

        friend void swap(matm<T>& r, matm<T>& l);

        matm& operator=(const matm& rhs);
        matm& operator=(matm&& rhs);
        matm operator*(const matm& rhs) const;
        const matm& operator*=(const matm& rhs);
        const T* operator*()const;


        void identity();

        void zero();

        };

#endif
