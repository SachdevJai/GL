
#ifndef OPENGLRAND_VBO_H
#define OPENGLRAND_VBO_H

#include "glad/glad.h"

class VBO {
public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size);
    void Bind();
    void Unbind();
    void Delete();
};


#endif
