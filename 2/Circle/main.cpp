#include "circle.cpp"
#include <iostream>

using namespace std;

int main() {
    Circle mas[3];
    for (int i = 0; i < 3; i++) {
        cout << "Insert circle parameters:";
        float r, x, y;
        cin >> r >> x >> y;
        mas[i].set_circle(r, x, y);
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " circle:" << endl;
        cout << "S = " << mas[i].square() << endl;
        cout << "Triangle around parameters:";
        float a,b,c;
        cin >> a >> b >> c;
        mas[i].triangle_around(a, b, c) == 1 ? cout << "True" : cout << "False";
        cout << endl << "Triangle in parameters:";
        cin >> a >> b >> c; 
        mas[i].triangle_in(a, b, c) == 1 ? cout << "True" : cout << "False";
        cout << endl << "check circle parameters:";
        float r, x_cntr, y_cntr;
        cin >> r >> x_cntr >> y_cntr; 
        mas[i].check_circle(r, x_cntr, y_cntr) == 1 ? cout << "True" : cout << "False";
    }

    return 0;
}