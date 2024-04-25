#ifndef SQUARE_H
#define SQUARE_H

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
