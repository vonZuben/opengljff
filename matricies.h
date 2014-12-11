#ifndef MATRICIES_H
#define MATRICIES_H

#include<algorithm>
#include<initializer_list>

        // row major matricies for use with opengl and glm. transormations are done
        // for opengl which is column major therefor everything is inversed
template<typename T>
class matm;

template <typename T>
void swap(matm<T>& r, matm<T>& l);

template<typename T>
class matm{

    private:

        int size; // i figure this makes it more general just in case
        T* mat;

    public:

        matm(int _size = 0) :
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

        friend void swap <T>(matm<T>& r, matm<T>& l);

        matm<T> operator=(const matm<T>& rhs);
        matm<T> operator=(matm<T>&& rhs);
        matm<T> operator*(const matm<T>& rhs) const;
        const matm<T>& operator*=(const matm<T>& rhs);
        const T* operator*()const;


        void identity();

        void zero();

        };

template<typename T>
void swap(matm<T>& r, matm<T>& l){
    std::swap(r.size, l.size);
    std::swap(r.mat, l.mat);
}

template<typename T>
void matm<T>::identity(){ // should only be used on matrices that are thought of as square
    zero();
    for (int i = 0; i < size; i += std::sqrt(size) + 1)
        mat[i] = 1;
}

template<typename T>
void matm<T>::zero(){
    std::fill(&mat[0], &mat[size], 0);
}

template<typename T>
const T* matm<T>::operator*()const{
    return mat;
}

template<typename T>
matm<T> matm<T>::operator=(const matm<T>& rhs){
    matm<T> tmp(rhs); // I do this so that I can have sudo copy swap assignment operator and move assignment
    swap(*this, tmp);
    return *this;
}

template<typename T>
matm<T> matm<T>::operator=(matm<T>&& rhs){ // lets me avoid creating a copy for no reason
    swap(*this, rhs);
    return *this;
}

template<typename T>
matm<T> matm<T>::operator*(const matm<T>& rhs) const{

    matm<T> t(rhs.size);
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

template<typename T>
const matm<T>& matm<T>::operator*=(const matm<T>& rhs){

    *this = *this * rhs;

    return *this;
}

// the following functions are for 4 x 4 matricise only


#endif
