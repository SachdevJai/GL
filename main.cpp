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

enum colors {
    WHITE,
    YELLOW,
    BLUE,
    GREEN,
    RED,
    ORANGE
};

glm::vec3 colors[6] = {
    glm::vec3(1.0f, 1.0f, 1.0f), // WHITE
    glm::vec3(1.0f, 0.95f, 0.0f), // YELLOW
    glm::vec3(0.0f, 0.0f, 1.0f), // BLUE
    glm::vec3(0.0f, 1.0f, 0.0f), // GREEN
    glm::vec3(1.0f, 0.0f, 0.0f), // RED
    glm::vec3(1.0f, 0.6f, 0.2f) // ORANGE
};

const unsigned int DIM = 3;

int SCR_WIDTH = 800;
int SCR_HEIGHT = 800;

void printModelMatrix(glm::mat4 mat1);
void draw (Shader& shader, VAO& VAO1);

void showFps(GLfloat& currTime, GLfloat& deltaTime, GLfloat& prevTime, int& fps);

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

    GLfloat scale = 2.0f / ((float)DIM);

    model.ModelMatrix = glm::scale(model.ModelMatrix, glm::vec3(scale));

    // Set up OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glfwSwapInterval(1);

    GLfloat prevTime = 0.0f;
    GLfloat currTime = 0.0f;
    GLfloat deltaTime = 0.0f;
    int fps;

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        showFps(currTime, prevTime, deltaTime, fps);
        // Use shader program
        shader.Use();

        // Update camera and model matrices
        draw(shader, VAO1);
        camera.Matrix(45.0f, 0.1f, 100.f, shader, "camMatrix");
        model.Matrix(shader, "modelMatrix");

        camera.Inputs(window);
        model.Inputs(window);

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

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

void showFps(GLfloat& currTime, GLfloat& deltaTime, GLfloat& prevTime, int& fps) {
    currTime = glfwGetTime();
    deltaTime = currTime - prevTime;
    fps = 1 / deltaTime;
    prevTime = currTime;
    std::cout << fps << std::endl;

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


void draw(Shader& shader, VAO& VAO1) {
    for (int face = 0; face < 6; face++) {
        switch (face) {
            // WHITE FACE
            case 0:
                for (int row = 0; row < DIM; row++) {
                    for (int col = 0; col < DIM; col++) {
                        glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, DIM, col));
                        facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                        glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(colors[WHITE]));
                        // Draw the quad
                        VAO1.Bind();
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                        VAO1.Unbind();
                    }
                }
                break;
                // YELLOW FACE
            case 1:
                for (int row = 0; row < DIM; row++) {
                    for (int col = 0; col < DIM; col++) {
                        glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, 0, col));
                        facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                        glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(colors[YELLOW]));
                        // Draw the quad
                        VAO1.Bind();
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                        VAO1.Unbind();
                    }
                }
                break;
                // BLUE FACE
            case 2:
                for (int row = 0; row < DIM; row ++) {
                    for (int col = 0; col < DIM; col ++) {
                        glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, col + 1, 0));
                        facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                        facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                        glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(colors[BLUE]));
                        // Draw the quad
                        VAO1.Bind();
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                        VAO1.Unbind();

                    }

                }
                break;
                // GREEN FACE
            case 3:
                for (int row = 0; row < DIM; row ++) {
                    for (int col = 0; col < DIM; col ++) {
                        glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(row, col + 1, DIM));
                        facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
                        facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                        glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(colors[GREEN]));
                        // Draw the quad
                        VAO1.Bind();
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                        VAO1.Unbind();

                    }

                }
                break;
                // RED FACE
            case 4:
                for (int row = 0; row < DIM; row++) {
                    for (int col = 0; col < DIM; col++) {
                        glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(DIM, row , col));
                        facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                        facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                        glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(colors[RED]));
                        // Draw the quad
                        VAO1.Bind();
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                        VAO1.Unbind();

                    }
                }
                break;
                // ORANGE FACE
            case 5:
                for (int row = 0; row < DIM; row++) {
                    for (int col = 0; col < DIM; col++) {
                        glm::mat4 facemat = glm::translate(glm::mat4(1.0f), glm::vec3(0, row , col));
                        facemat = glm::rotate(facemat, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                        facemat = glm::scale(facemat, glm::vec3(0.98f, 0.98f, 0.98f));
                        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "faceMatrix"), 1, GL_FALSE, glm::value_ptr(facemat));
                        glUniform3fv(glGetUniformLocation(shader.ID, "aColor"), 1, glm::value_ptr(colors[ORANGE]));
                        // Draw the quad
                        VAO1.Bind();
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
                        VAO1.Unbind();

                    }
                }
                break;

        }
    }
}
