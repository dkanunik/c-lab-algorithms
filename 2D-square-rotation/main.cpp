#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "include/Shapes.h"

double downX = 0;
double downY = 0;
double diffX = 0;
double diffY = 0;

unsigned short int gainDivider = 500;

Shapes square;

Point calculatePointLocation(Point point, double angleInRad) {
    Point result;
    result.x = static_cast<float>(point.x * cos(angleInRad) - point.y * sin(angleInRad));
    result.y = static_cast<float>(point.x * sin(angleInRad) + point.y * cos(angleInRad));
    return result;
}

double calculateAngleForRotation(double degrees) {
    return degrees * M_PI / HALF_OF_CIRCLE;
}


double calculateGainOfMoving() {
    return diffX / gainDivider;
}

void calculateSquareLocation() {
    double gain = calculateGainOfMoving();
    double angleInRad = calculateAngleForRotation(gain);

    Point result = calculatePointLocation(square.top_left, angleInRad);
    square.top_left = result;

    result = calculatePointLocation(square.top_right, angleInRad);
    square.top_right = result;

    result = calculatePointLocation(square.bottom_right, angleInRad);
    square.bottom_right = result;

    result = calculatePointLocation(square.bottom_left, angleInRad);
    square.bottom_left = result;
}

void cursorPosCallback(GLFWwindow *window, double xpos, double ypos) {
    double currentX = 0;
    double currentY = 0;

    int mouseButtonCondition = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    glfwGetCursorPos(window, &currentX, &currentY);
    if (mouseButtonCondition == GLFW_PRESS) {
        std::cout << "POS: (" << currentX << ", " << currentY << ")" << std::endl;
        if (downX == 0) {
            downX = currentX;
            downY = currentY;
            std::cout << "INIT: (" << downX << ", " << downY << ")" << std::endl;
        }

        diffX = currentX - downX;
        diffY = downY - currentY;
        std::cout << "DIFF: (" << diffX << ", " << diffY << ")" << std::endl;
        calculateSquareLocation();
    }

    if (mouseButtonCondition == GLFW_RELEASE) {
        downX = 0;
        downY = 0;
    }
}

void drawBox() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);              // Set color
    glVertex2f(square.bottom_left.x, square.bottom_left.y);     // Bottom-left vertex
    glVertex2f(square.bottom_right.x, square.bottom_right.y);   // Bottom-right vertex
    glVertex2f(square.top_right.x, square.top_right.y);         // Top-right vertex
    glVertex2f(square.top_left.x, square.top_left.y);           // Top-left vertex
    glEnd();
}

void renderScene(GLFWwindow *window) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBox();
    glfwSwapBuffers(window);
}

void intGlobalValues() {
    diffX = 50;
    diffY = 50;

    square = {
            .top_left = {-0.5f, 0.5f},
            .top_right = {0.5f, 0.5f},
            .bottom_left = {-0.5f, -0.5f},
            .bottom_right = {0.5f, -0.5f}
    };
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(WINDOW_W, WINDOW_H, "OpenGL Line", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    intGlobalValues();
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
