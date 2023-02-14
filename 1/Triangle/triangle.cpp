#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
    private:
    double a, b, c;

    public:
    bool exst_tr() {
        return (a < b + c) && (b < a + c) && (c < a + b);
    }
    void set(double a1, double b1, double c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    void show() {
        cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;;
    }
    double perimeter() {
        return a + b + c;
    }
    double square() {
        double p = perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() {
    setlocale(0, "");

    Triangle mas[3];
    for (int i = 0; i < 3; i++) {
        cout << "Введите стороны треугольника:";
        double a, b, c;
        cin >> a >> b >> c;
        mas[i].set(a, b, c);
        if (mas[i].exst_tr() == false) {
            cout << "Треугольник с такими сторонами не может существовать" << endl;
            i--;
        }
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        mas[i].show();
        cout << "P = " << mas[i].perimeter() << endl;
        cout << "S = " << mas[i].square() << endl << endl;
    }

    return 0;
}