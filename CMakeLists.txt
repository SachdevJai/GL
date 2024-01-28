cmake_minimum_required(VERSION 3.26)
project(openglRand)

set(CMAKE_CXX_STANDARD 17)

add_executable(openglRand main.cpp glad/glad.c
        Shader.cpp
        Shader.h
        VBO.cpp
        VBO.h
        EBO.cpp
        EBO.h
        VAO.cpp
        VAO.h
        Camera.cpp
        Camera.h
        Model.cpp
        Model.h
        Cubie.cpp
        Cubie.h
)
target_link_libraries(openglRand glfw)

