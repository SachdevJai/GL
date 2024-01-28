#include "Model.h"

Model::Model() {
    ModelMatrix = glm::mat4(1.0f);
}

void Model::Matrix(Shader& shader, const char* uniform) {
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(ModelMatrix));
}

void Model::Inputs(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(-1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(-1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }
}