#include "rational.h"
#include <iostream>

using namespace std;

int NOD (int a, int b) {
    int NOD = 1;
    int tempA = a;
    for (int i = 2; i <= tempA; i++) {
        if (tempA % i == 0 and b % i == 0) {
            NOD *= i;
            tempA /= i;
        }
    }
    return NOD;
}

rational :: rational () {
    a = 0;
    b = 0;
}

rational :: rational (int a1, int b1) {
    int nod = NOD(a1, b1);
    a = a1 / nod;
    b = b1 / nod;
}

void rational :: set (int a1, int b1) {
    int nod = NOD(a1, b1);
    a = a1 / nod;
    b = b1 / nod;
}

void rational :: show () {
    cout << a << '/' << b << endl;
}

int rational :: get_a () {
    return a;
}

int rational :: get_b () {
    return b;
}

rational operator - (rational &d1, rational &d2) {
    int newA = d1.get_a() * d2.get_b() - d2.get_a() * d1.get_b();
    int newB = d1.get_b() * d2.get_b();
    int nod = NOD(newA, newB);
    rational temp (newA / nod, newB / nod);
    return temp;
}

rational rational::operator= (rational frac) {
    a = frac.a;
    b = frac.b;
    return *this;
}
