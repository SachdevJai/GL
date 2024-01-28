#ifndef CUBE_SHADER_H
#define CUBE_SHADER_H

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class Shader {
public:
    GLuint ID;
    Shader (const GLchar* vsrc, const GLchar* fsrc);
    void Use();
    void Delete();
};


#endif