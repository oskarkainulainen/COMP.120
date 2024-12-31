#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int width;
    int height;
    Point origin;
} Rectangle;

Rectangle * createRectangle();
Rectangle * createRectangle2(Point origin);
Rectangle * createRectangle3(int w, int h);
Rectangle * createRectangle4(Point origin, int w, int h);
int getArea(Rectangle * r);
void move(Rectangle * r, int x, int y);

#endif /* RECTANGLE_H */

