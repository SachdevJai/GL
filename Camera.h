#ifndef OPENGLRAND_CAMERA_H
#define OPENGLRAND_CAMERA_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "Shader.h"

class Camera {
public:
    glm::vec3 cameraPos;
    glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

    int width;
    int height;

    float speed = 0.1f;
    float sensitivity = 100.0f;

    Camera(int height, int width, glm::vec3 position);

    void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
    void Inputs(GLFWwindow* window);
};


#endif //OPENGLRAND_CAMERA_H
