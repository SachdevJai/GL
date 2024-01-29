//#ifndef OPENGLRAND_CUBIE_H
//#define OPENGLRAND_CUBIE_H
//
//#include "glad/glad.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <glm/gtx/vector_angle.hpp>
//#include <glm/gtx/rotate_vector.hpp>
//#include "Shader.h"
//#include "VAO.h"
//#include "VBO.h"
//#include "EBO.h"
//#include "Model.h"
//
//GLfloat vertices[] = {
//        // Front
//        -0.5f,-0.5f,-0.5f, 0.0f, 1.0f, 0.0, // 0
//        0.5f,-0.5f,-0.5f, 0.0f, 1.0f, 0.0f, // 1
//        0.5f,0.5f,-0.5f, 0.0f, 1.0f, 0.0f,// 2
//        -0.5f,0.5f,-0.5f, 0.0f, 1.0f, 0.0f,// 3
//
//        // Top
//        -0.5f,0.5f,-0.5f, 1.0f, 1.0f, 1.0f,// 4
//        0.5f,0.5f,-0.5f, 1.0f, 1.0f, 1.0f,// 5
//        0.5f,0.5f,0.5f, 1.0f, 1.0f, 1.0f,// 6
//        -0.5f,0.5f,0.5f, 1.0f, 1.0f, 1.0f,// 7
//
//        // Back
//        -0.5f,-0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 8
//        0.5f,-0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 9
//        0.5f,0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 10
//        -0.5f,0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 11
//
//        // Bottom
//        -0.5f,-0.5f,-0.5f, 0.9f, 0.9f, 0.2f,// 12
//        0.5f,-0.5f,-0.5f, 0.9f, 0.9f, 0.2f,// 13
//        0.5f,-0.5f,0.5f, 0.9f, 0.9f, 0.2f,// 14
//        -0.5f,-0.5f,0.5f, 0.9f, 0.9f, 0.2f,// 15
//
//        // Left
//        -0.5f,-0.5f,0.5f, 1.0f, 0.0f, 0.0f,// 16
//        -0.5f,-0.5f,-0.5f, 1.0f, 0.0f, 0.0f,// 17
//        -0.5f,0.5f,-0.5f, 1.0f, 0.0f, 0.0f,// 18
//        -0.5f,0.5f,0.5f, 1.0f, 0.0f, 0.0f,// 19
//
//        // Right
//        0.5f,-0.5f,0.5f, 0.9f, 0.6f, 0.0f,// 20
//        0.5f,-0.5f,-0.5f, 0.9f, 0.6f, 0.0f,// 21
//        0.5f,0.5f,-0.5f, 0.9f, 0.6f, 0.0f,// 22
//        0.5f,0.5f,0.5f, 0.9f, 0.6f, 0.0f,// 23
//
//};
//
//GLuint indices[] = {
//        // Front Face
//        0, 1, 2,
//        2, 3, 0,
//        // Top Face
//        4, 5, 6,
//        6, 7, 4,
//        // Back Face
//        8, 9, 10,
//        10, 11, 8,
//        // Bottom Face
//        12, 13, 14,
//        14, 15, 12,
//        // Left Face
//        16, 17, 18,
//        18, 19, 16,
//        // Right Face
//        20, 21, 22,
//        22, 23, 20
//};
//
//
//class Cubie {
//    glm::vec3 position;
//
//    Cubie(glm::vec3 pos);
//    void draw(glm::vec3 pos);
//};
//
//
//#endif
