#include "eq2.h"
#include <iostream>
#include <cmath>

using namespace std;

eq2 :: eq2 (double a1, double b1, double c1) {
    a = a1; b = b1; c = c1;
    D = b * b - 4 * a  * c;
}

void eq2 :: set (double a1, double b1, double c1) {
    a = a1; b = b1; c = c1;
    D = b * b - 4 * a  * c;
}

double eq2 :: find_X () {
    if (D < 0) {
        cout << "Корней нет" << endl;
        return 0;
    }

    if (D == 0) {
        cout << "Корень один:";
        double x = -1 * b / (2 * a);
        cout << x << endl; 
        return x;
    }

    cout << "Корня два наибольший:";
    double x1 = (-1 * b + sqrt(D)) / (2 * a);
    double x2 = (-1 * b - sqrt(D)) / (2 * a);

    if (x1 > x2) {
        cout << x1 << endl;
        return x1;
    } else {
        cout << x2 << endl;
        return x2;
    }
}

double eq2 :: find_Y (double x1) {
    return  a * x1 * x1 + b * x1 + c;
}

int eq2 :: get_a () {
    return a;
}
int eq2 :: get_b () {
        return b;
}
int eq2 :: get_c () {
    return c;
}

