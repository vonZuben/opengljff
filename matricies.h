#ifndef MATRICIES_H
#define MATRICIES_H

        // row major matricies for use with opengl and glm. transormations are done
        // for opengl which is column major therefor everything is inversed
class matm{

    private:

        float mat[4][4];

    public:

        matm();

        matm(bool loadIdentity);

        ~matm();

        void identity();

        void perspective(float fov, float aspectRatio, float near, float far);

        void xRotation(float angle);

        void yRotation(float angle);

        void zRotation(float angle);

        void translate(float x, float y, float z);

        float* val();

        const matm& operator=(const matm& rhs);
        matm operator*(const matm& rhs) const;
        const matm& operator*=(const matm& rhs);

};

#endif
