#include "eq2.cpp"
#include <iostream>
using namespace std;

eq2 operator + (eq2 &e1, eq2 &e2) {
    eq2 temp(e1.get_a() + e2.get_a(), e1.get_b() + e2.get_b(), e1.get_c() + e2.get_c());
    return temp;
}


int main() {
    double a,b,c;
    cin >> a >> b >> c;
    eq2 ur1(a, b, c);
    cin >> a >> b >> c;
    eq2 ur2(a, b, c);
    eq2 ur3 = ur1 + ur2;
    cout << ur3.find_X();

    return 0;
}

//ДРУЖЕСТВЕННАЯ ЧЕРЕЗ FRIEND ВНУТРИ КЛАССА