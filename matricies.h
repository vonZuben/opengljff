#ifndef MATRICIES_H
#define MATRICIES_H

        // column major matricies for use with opengl and glm
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

};

#endif
