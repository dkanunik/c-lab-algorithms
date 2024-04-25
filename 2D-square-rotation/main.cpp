#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

double downX = 0;
double downY = 0;
double diffX = 0;
double diffY = 0;

void cursorPosCallback(GLFWwindow *window, double xpos, double ypos) {
    double currentX = 0;
    double currentY = 0;

    int mouseButtonCondition = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    glfwGetCursorPos(window, &currentX, &currentY);
    if (mouseButtonCondition == GLFW_PRESS) {
        std::cout << "Mouse position: (" << currentX << ", " << currentY << ")" << std::endl;
        if (downX == 0) {
            downX = currentX;
            downY = currentY;
            std::cout << "INIT: (" << downX << ", " << downY << ")" << std::endl;
        }
    }

    if (mouseButtonCondition == GLFW_RELEASE && (downX != 0 || downY != 0)) {
        diffX = currentX - downX;
        diffY = currentY - downY;
        std::cout << "DIFF: (" << diffX << ", " << diffY << ")" << std::endl;
        downX = 0;
        downY = 0;
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
    glfwSetCursorPosCallback(window, cursorPosCallback);

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
