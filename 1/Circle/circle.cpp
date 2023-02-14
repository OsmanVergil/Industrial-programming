#include "circle.h"
#include <cmath>

Circle :: Circle() {
    radius = 0;
    x_center = 0;
    y_center = 0;
};
Circle :: Circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
};
void Circle :: set_circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
}
float Circle :: square() {
    return M_PI * radius * radius;
}
bool Circle :: triangle_around(float a, float b, float c) {
    float cos = (a * a + b * b - c * c) / (2 * a * b);
    float sin = sqrt(1 - cos * cos);
    return (c / sin) == (2 * radius);
}
bool Circle :: triangle_in(float a, float b, float c) {
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return radius == (s / p);
}
bool Circle :: check_circle(float r, float x_cntr, float y_cntr) {
    float distBetweenCenters = sqrt(pow(x_center - x_cntr, 2) + pow(y_center - y_cntr, 2));
    bool isInside = false;
    if (r > radius) {
        if (pow(x_center - x_cntr, 2) + pow(y_center - y_cntr, 2) <= (r * r)) isInside = true;
        if (isInside) return (distBetweenCenters + radius) > r;
        else return distBetweenCenters < (r + radius);
    } else {
        if (pow(x_center - x_cntr, 2) + pow(y_center - y_cntr, 2) <= (radius * radius)) isInside = true;
        if (isInside) return (distBetweenCenters + r) > radius;
        else return distBetweenCenters < (r + radius);
    }
}
