#include <stdlib.h>
#include "rectangle.h"

Rectangle * createRectangle() {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle));
    if (rect != NULL) {
        rect->width = 0;
        rect->height = 0;
        rect->origin.x = 0;
        rect->origin.y = 0;
    }
    return rect;
}

Rectangle * createRectangle2(Point origin) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle));
    if (rect != NULL) {
        rect->width = 0;
        rect->height = 0;
        rect->origin = origin;
    }
    return rect;
}

Rectangle * createRectangle3(int w, int h) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle));
    if (rect != NULL) {
        rect->width = w;
        rect->height = h;
        rect->origin.x = 0;
        rect->origin.y = 0;
    }
    return rect;
}

Rectangle * createRectangle4(Point origin, int w, int h) {
    Rectangle *rect = (Rectangle *)malloc(sizeof(Rectangle));
    if (rect != NULL) {
        rect->width = w;
        rect->height = h;
        rect->origin = origin;
    }
    return rect;
}

int getArea(const Rectangle *r) {
    return r->width * r->height;
}

void move(Rectangle *r, int x, int y) {
    r->origin.x = x;
    r->origin.y = y;
}

