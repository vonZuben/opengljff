#ifndef MATRICIES_H
#define MATRICIES_H

#include<algorithm>
#include<initializer_list>

//must add proper documentation

        // row major matricies for use with opengl and glm. transormations are done
        // for opengl which is column major therefor everything is inversed

template<typename T>
class matm{

    private:

        int height;
        int width;
        T* mat;

    public:

        inline const int size()const{
            return height * width;
        }

        matm(int _height, int _width) :
            height(_height),
            width(_width),
            mat(size() ? new T[size()] : 0)
            {}

        matm(const matm& other) :
            height(other.height),
            width(other.width),
            mat(size() ? new T[size()] : 0)
            {
                std::copy(other.mat, other.mat + (size()), mat);
            }

        matm(matm&& other) : matm(0, 0) {
            swap(*this, other);
        }

        matm(std::initializer_list<T> l, int _height, int _width) : matm(_height, _width) {
            T* tmp = mat;
            //static_assert(size() == l.size(), "matrix size is wrong for the list given");
            for (T i : l)
                *tmp++ = i;
        }

        ~matm(){
            delete[] mat;
        }

        inline friend void swap(matm<T>& r, matm<T>& l){
            std::swap(r.height, l.height);
            std::swap(r.width, l.width);
            std::swap(r.mat, l.mat);
        }

        inline T* operator[](int r)const{
            return mat + (this->width * r);
        }

        inline const T* operator*()const{
            return mat;
        }

        inline void zero(){
            std::fill(&mat[0], &mat[size()], 0);
        }

        matm<T> operator=(const matm<T>& rhs){
            matm<T> tmp(rhs); // I do this so that I can have sudo copy swap assignment operator and move assignment
            swap(*this, tmp);
            return *this;
        }

        matm<T> operator=(matm<T>&& rhs){ // lets me avoid creating a copy for no reason
            swap(*this, rhs);
            return *this;
        }

        matm<T> operator*(const matm<T>& rhs) const{

            matm<T> t(this->height, rhs.width);
            t.zero();

            for (int row = 0; row < t.height; ++row) {
                for (int col = 0; col < t.width; ++col) {
                    for (int inner = 0; inner < t.height; ++inner) { // pretty sure this doesn't work for differently shaped matrices
                        t[row][col] += (*this)[row][inner] * rhs[inner][col];
                    }
                }
            }

            return t;
        }

        matm<T>& operator*=(const matm<T>& rhs){
            *this = *this * rhs;
            return *this;
        }

};

#endif
