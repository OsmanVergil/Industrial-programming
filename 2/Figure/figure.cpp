#include "figure.h"
#include "cmath"
#include <iostream>

using namespace std;

float dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float square(float a, float b, float c) {
        float p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

Figure :: Figure(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) {
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
    this->x4 = x4;
    this->y1 = y1;
    this->y2 = y2;
    this->y3 = y3;
    this->y4 = y4;

    //тут нахожу длины сторон, это будет повторяться)
    float a = dist(x1,y1,x2,y2), b = dist(x2,y2,x3,y3), c = dist(x3,y3,x4,y4), d = dist(x4,y4,x1,y1);
    P = a + b + c + d;
    float diag = dist(x1,y1,x3,y3);
    S = square(a, b, diag) + square(c, d, diag);
}
void Figure :: show() {
    cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl << "x3 = " << x3 << endl << "x4 = " << x4 << endl << "y1 = " << y1 << endl << "y2 = " << y2 << endl << "y3 = " << y3 << endl << "y4 = " << y4 << endl;
    cout << "P = " << P << endl << "S = " << S << endl;
}
bool Figure :: is_prug() {
    float a = dist(x1,y1,x2,y2), b = dist(x2,y2,x3,y3), c = dist(x3,y3,x4,y4), d = dist(x4,y4,x1,y1);
    float diag1 = dist(x1,y1,x3,y3), diag2 = dist(x2,y2,x4,y4);
    if (a == c && b == d && diag1 == diag2) return true;
    else return false;
}
bool Figure :: is_square() {
    float a = dist(x1,y1,x2,y2), b = dist(x2,y2,x3,y3), c = dist(x3,y3,x4,y4), d = dist(x4,y4,x1,y1);
    float diag1 = dist(x1,y1,x3,y3), diag2 = dist(x2,y2,x4,y4);
    if (a == b && b == c && c == d && diag1 == diag2) return true;
    else return false;
}
bool Figure :: is_romb() {
    float a = dist(x1,y1,x2,y2), b = dist(x2,y2,x3,y3), c = dist(x3,y3,x4,y4), d = dist(x4,y4,x1,y1);
    if (a == b && b == c && c == d) return true;
    else return false;
}
bool Figure :: is_in_circle() {
    float a = dist(x1,y1,x2,y2), b = dist(x2,y2,x3,y3), c = dist(x3,y3,x4,y4), d = dist(x4,y4,x1,y1);
    float diag = dist(x1,y1,x3,y3);
    float cos1 = (a * a + b * b - diag * diag) / (2 * a * b), cos2 = (c * c + d * d - diag * diag) / (2 * c * d);
    float angle1 = acos(cos1) * 180 / M_PI, angle2 = acos(cos2) * 180 / M_PI;
    return (angle1 + angle2) == 180; 
}
bool Figure :: is_out_circle() {
    float a = dist(x1,y1,x2,y2), b = dist(x2,y2,x3,y3), c = dist(x3,y3,x4,y4), d = dist(x4,y4,x1,y1);
    return a + c == b + d;
}