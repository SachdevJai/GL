#ifndef OPENGLRAND_MODEL_H
#define OPENGLRAND_MODEL_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "Shader.h"

class Model {
public:
    Model();
    void Inputs(GLFWwindow* window);
    void Matrix(Shader& shader, const char* uniform);
    glm::mat4 ModelMatrix;
    ~Model() = default;
};


#endif
