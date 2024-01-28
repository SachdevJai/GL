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

// Vertices coordinates
GLfloat vertices[] = {
        // Front
        -0.5f,-0.5f,-0.5f, 0.0f, 1.0f, 0.0, // 0
        0.5f,-0.5f,-0.5f, 0.0f, 1.0f, 0.0f, // 1
        0.5f,0.5f,-0.5f, 0.0f, 1.0f, 0.0f,// 2
        -0.5f,0.5f,-0.5f, 0.0f, 1.0f, 0.0f,// 3

        // Top
        -0.5f,0.5f,-0.5f, 1.0f, 1.0f, 1.0f,// 4
        0.5f,0.5f,-0.5f, 1.0f, 1.0f, 1.0f,// 5
        0.5f,0.5f,0.5f, 1.0f, 1.0f, 1.0f,// 6
        -0.5f,0.5f,0.5f, 1.0f, 1.0f, 1.0f,// 7

        // Back
        -0.5f,-0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 8
        0.5f,-0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 9
        0.5f,0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 10
        -0.5f,0.5f,0.5f, 0.0f, 0.0f, 1.0f,// 11

        // Bottom
        -0.5f,-0.5f,-0.5f, 0.9f, 0.9f, 0.2f,// 12
        0.5f,-0.5f,-0.5f, 0.9f, 0.9f, 0.2f,// 13
        0.5f,-0.5f,0.5f, 0.9f, 0.9f, 0.2f,// 14
        -0.5f,-0.5f,0.5f, 0.9f, 0.9f, 0.2f,// 15

        // Left
        -0.5f,-0.5f,0.5f, 1.0f, 0.0f, 0.0f,// 16
        -0.5f,-0.5f,-0.5f, 1.0f, 0.0f, 0.0f,// 17
        -0.5f,0.5f,-0.5f, 1.0f, 0.0f, 0.0f,// 18
        -0.5f,0.5f,0.5f, 1.0f, 0.0f, 0.0f,// 19

        // Right
        0.5f,-0.5f,0.5f, 0.9f, 0.6f, 0.0f,// 20
        0.5f,-0.5f,-0.5f, 0.9f, 0.6f, 0.0f,// 21
        0.5f,0.5f,-0.5f, 0.9f, 0.6f, 0.0f,// 22
        0.5f,0.5f,0.5f, 0.9f, 0.6f, 0.0f,// 23

};

GLuint indices[] = {
        // Front Face
        0, 1, 2,
        2, 3, 0,
        // Top Face
        4, 5, 6,
        6, 7, 4,
        // Back Face
        8, 9, 10,
        10, 11, 8,
        // Bottom Face
        12, 13, 14,
        14, 15, 12,
        // Left Face
        16, 17, 18,
        18, 19, 16,
        // Right Face
        20, 21, 22,
        22, 23, 20
};


int SCR_WIDTH = 800;
int SCR_HEIGHT = 800;

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

    glEnable(GL_DEPTH_TEST);

    Shader shader("../shader.vs", "../shader.fs");
    Camera camera(SCR_HEIGHT, SCR_WIDTH, glm::vec3(3.0f, 3.0f, 3.0f));
    Model model;


    // Create Vertex Array Object
    VAO VAO1;
    VAO1.Bind();
    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));
    // This shit defines how to draw 1 triangle
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float),(void *)(3 * sizeof(float)));
    // Unbind everything
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.Use();


        camera.Matrix(45.0f, 0.1f, 100.f, shader, "camMatrix");
        model.Matrix(shader, "modelMatrix");

        model.Inputs(window);
        camera.Inputs(window);
        if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, 1);
        }

        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
        VAO1.Unbind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    // Delete all the objects we've created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shader.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}


