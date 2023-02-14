#include "circle.h"
#include <cmath>

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
    return 3.14 * radius * radius;
}
bool Circle :: check_circle(float r, float x_cntr, float y_cntr) {
    float distBetweenCenters = sqrt(pow(x_center - x_cntr, 2) + pow(y_center - y_cntr, 2));
    return true;
}
