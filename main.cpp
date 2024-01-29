#include<iostream>
#include"glad/glad.h"
#include<GLFW/glfw3.h>
#include<cmath>

#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Camera.h"
#include "Model.h"

GLfloat vertices[] = {
        // TOP
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
};

GLuint indices[] = {
        // TOP
        0, 1, 2,
        0, 2, 3,
};

GLuint state[6][3][3];

const unsigned int DIM = 50;

int SCR_WIDTH = 800;
int SCR_HEIGHT = 800;

void printModelMatrix(glm::mat4 mat1);

int main () {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Window object
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "opengL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // initialize GLAD
    gladLoadGL();
    // Viewport
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                state[i][j][k] = i;
            }
        }
    }

    VAO VAO1;
    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));
    VAO1.Bind();
    VBO1.Bind();
    EBO1.Bind();
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    VAO1.Unbind();

    // Set up the camera, shader, VAO, and model
    Camera camera(800, 600, glm::vec3(3.0f, 3.0f, 3.0f));
    Shader shader("../shader.vs", "../shader.fs");
    Model model;

    model.ModelMatrix = glm::scale(model.ModelMatrix, glm::vec3(2/((float)DIM)));


    // Set up OpenGL settings
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use shader program
        shader.Use();

        // Update camera and model matrices
        for (int face = 0; face < 6; face++) {
            switch (face) {
                case 0:
                    for (int row = 0; row < DIM; row++) {
                        for (int col = 0; col < DIM; col++) {
                            glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, DIM, col));
                            facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                            glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));
                            // Draw the quad
                            VAO1.Bind();
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                            VAO1.Unbind();
                        }
                    }
                    break;
                case 1:
                    for (int row = 0; row < DIM; row++) {
                        for (int col = 0; col < DIM; col++) {
                            glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, 0, col));
                            facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                            glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(glm::vec3(1.0f, 0.95f, 0.0f)));
                            // Draw the quad
                            VAO1.Bind();
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                            VAO1.Unbind();
                        }
                    }
                    break;
                case 2:
                    for (int row = 0; row < DIM; row ++) {
                        for (int col = 0; col < DIM; col ++) {
                            glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, col + 1, 0));
                            facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                            facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                            glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(glm::vec3(0.0f, 0.0f, 1.0f)));
                            // Draw the quad
                            VAO1.Bind();
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                            VAO1.Unbind();

                        }

                    }
                    break;
                case 3:
                    for (int row = 0; row < DIM; row ++) {
                        for (int col = 0; col < DIM; col ++) {
                            glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, col + 1, DIM));
                            facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                            facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                            glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(glm::vec3(0.0f, 1.0f, 0.0f)));
                            // Draw the quad
                            VAO1.Bind();
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                            VAO1.Unbind();

                        }

                    }
                    break;
                case 4:
                    for (int row = 0; row < DIM; row++) {
                        for (int col = 0; col < DIM; col++) {
                            glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(DIM, row , col));
                            facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                            facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                            glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(glm::vec3(1.0f, 0.0f, 0.0f)));
                            // Draw the quad
                            VAO1.Bind();
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                            VAO1.Unbind();

                        }
                    }
                    break;
                case 5:
                    for (int row = 0; row < DIM; row++) {
                        for (int col = 0; col < DIM; col++) {
                            glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(0, row , col));
                            facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                            facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                            glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                            glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(glm::vec3(1.0f, 0.6f, 0.2f)));
                            // Draw the quad
                            VAO1.Bind();
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                            VAO1.Unbind();

                        }
                    }
                    break;

            }
        }
        camera.Matrix(45.0f, 0.1f, 100.f, shader, "camMatrix");
        model.Matrix(shader, "modelMatrix");

        camera.Inputs(window);
        model.Inputs(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    // Delete all the objects we've created
    shader.Delete();
    VBO1.Delete();
    EBO1.Delete();
    VAO1.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void printModelMatrix(glm::mat4 mat1) {
    for (int i = 0; i < 4; i++) {
        std::cout << "[ ";
        for (int j = 0; j < 4; j++) {
            std::cout << mat1[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}


