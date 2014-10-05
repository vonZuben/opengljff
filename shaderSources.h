#ifndef SHADERSOURCES_H
#define SHADERSOURCES_H

const char* srcvertex[] = {
    "#version 440 \n \
        layout(location=1)in vec3 position; \
        out vec3 pcolor; \
        void main(){ \
            gl_Position = vec4(position, 1.0);  \
            pcolor = vec3(abs(position.x), abs(position.y), abs(position.z)); \
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
