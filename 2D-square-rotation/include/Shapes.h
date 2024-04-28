#ifndef SQUARE_H
#define SQUARE_H

constexpr unsigned short int WINDOW_W = 600;
constexpr unsigned short int WINDOW_H = 600;
constexpr unsigned short int HALF_OF_CIRCLE = 180;

using Point = struct Point {
    GLfloat x;
    GLfloat y;
};

using Square = struct Shapes {
    Point top_left;
    Point top_right;
    Point bottom_left;
    Point bottom_right;
};

#endif //SQUARE_H
