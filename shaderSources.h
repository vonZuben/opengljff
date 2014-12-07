#ifndef SHADERSOURCES_H
#define SHADERSOURCES_H

const char* srcvertex[] = {
    "#version 440 \n \
        layout(location=1)in vec3 position; \
        layout(location=2)uniform mat4 worldViewCam; \
        layout(location=3)uniform mat4 transform; \
        layout(location=4)uniform mat4 camera; \
        out vec3 pcolor; \
        void main(){ \
            gl_Position = worldViewCam * camera * transform * vec4(position, 1.0);  \
            pcolor = position; \
        }"
};

const char* srcfragment[] = {
    "#version 440 \n \
        out vec4 color; \
        in vec3 pcolor; \
        void main(){ \
            color = vec4(pcolor, 1.0); \
        }"
};

const char* srccompute[] = {
    "#version 440 \n \
        \
        void main() { \
        }"
};
#endif
