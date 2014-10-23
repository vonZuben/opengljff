#ifndef MATRICIES_H
#define MATRICIES_H

        // row major matricies for use with opengl and glm. transormations are done
        // for opengl which is column major therefor everything is inversed
class matm{

    private:

        float* mat;

    public:

        matm();

        ~matm();

        void identity();

        void xRotation(float angle);

        void yRotation(float angle);

        float* val();

        const matm& operator=(const matm& rhs);
        matm operator*(const matm& rhs) const;
        const matm& operator*=(const matm& rhs);

};

#endif
