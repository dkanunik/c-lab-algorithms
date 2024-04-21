#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

float xDeviation = 0.0;

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    double mouseX = 0.0;
    double mouseY = 0.0;
    double releaseX = 0.0;
    double releaseY = 0.0;

    if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_LEFT) {
        glfwGetCursorPos(window, &mouseX, &mouseY);
        std::cout << "Mouse down at (" << mouseX << ", " << mouseY << ")" << std::endl;
    } else if (action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_LEFT) {
        glfwGetCursorPos(window, &releaseX, &releaseY);
        xDeviation = static_cast<float>(releaseX - mouseX);
        std::cout << "Mouse up at (" << releaseX << ", " << releaseY << ")" << std::endl;
        std::cout << "Mouse moved by (" << releaseX - mouseX << ", " << releaseY - mouseY << ")" << std::endl;
    }
}

void drawBox() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);       // Set color
    glVertex2f(-0.5f, -0.5f);     // Bottom-left vertex
    glVertex2f(0.5f, -0.5f);      // Bottom-right vertex
    glVertex2f(0.5f, 0.5f);       // Top-right vertex
    glVertex2f(-0.5f, 0.5f);      // Top-left vertex
    glEnd();
}

void renderScene(GLFWwindow *window) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBox();
    glfwSwapBuffers(window);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(600, 600, "OpenGL Line", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        renderScene(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
