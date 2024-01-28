#include "Shader.h"
#include <iostream>

std::string get_file_contents (const char* src) {
    std::ifstream file(src, std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file: " + std::string(src));
    }
    std::ostringstream contents;
    contents << file.rdbuf();
    return contents.str();
}

Shader::Shader(const char *vsrc, const char *fsrc) {
    std::string vertexCode = get_file_contents(vsrc);
    std::string fragmentCode = get_file_contents(fsrc);

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
    glCompileShader(fragmentShader);

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Use() {
    glUseProgram(ID);
}

void Shader::Delete() {
    glDeleteProgram(ID);
}