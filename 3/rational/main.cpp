#include "rational.cpp"
#include <iostream>

using namespace std;

rational operator + (rational &d1, rational &d2) {
    int newA = d1.get_a() * d2.get_b() + d2.get_a() * d1.get_b();
    int newB = d1.get_b() * d2.get_b();
    int nod = NOD(newA, newB);
    rational temp (newA / nod, newB / nod);
    return temp;
}

void operator++ (rational &d) {
    int newA = d.get_a() + 1;
    int newB = d.get_b();
    int nod = NOD(newA, newB);
    d.set (newA / nod, newB / nod);
}

bool operator == (rational &d1, rational &d2) {
    if (d1.get_a() == d2.get_a() and d1.get_b() == d2.get_b()) return true;
    else return false;
}

bool operator > (rational &d1, rational &d2) {
    if (d1.get_a() * d2.get_b()  > d2.get_a() * d1.get_b()) return true;
    else return false;
}


int main() {
    int n;
    cout << "Введите количество элементов";
    cin >> n;
    rational* arr = new rational[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= b and b != 0) {
            cout << "a >= b Числитель должен быть больше знаменателя, введите другие данные" << endl;
            --i;
        }
        if (b == 0) {
            cout << "b = 0 Знаменатель не может быть равен нулю, введите другие данные" << endl;
            --i;
        }
        rational frac (a, b);
        arr[i] = frac;
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " элемент: ";
        arr[i].show();
    }
    cout << "Пример для сложения: 1/3 + 1/2 = ";
    rational d1(1, 2), d2(1,3), d3 = d1 + d2;
    d3.show();

    cout << "Пример для вычитания: 4/5 - 2/3 = ";
    d1.set(4, 5); d2.set(2,3); d3 = d1 - d2;
    d3.show();

    cout << "Пример для инкремента: 3/8++ = ";
    d1.set(3, 8);
    ++d1;
    d1.show();

    d1.set(1,2); d2.set(1,3); d3.set(2, 4);
    cout << "Пример для сравнения (==): 1/2 == 1/3 -> " << (d1 == d2) << "; 1/2 == 2/4 -> " << (d1 == d3) << endl;

    d1.set(3,5); d2.set(2,3); d3.set(1, 4);
    cout << "Пример для сравнения (>): 3/5 > 2/3 -> " << (d1 > d2) << "; 3/5 > 1/4 -> " << (d1 > d3) << endl;

    //пример для присваивания (дроби не обращаются к одной памяти)
    d1.set(1,2);
    d2 = d1;
    d3.set(1,3);
    d2 = d2 - d3;
    d1.show();
    d2.show();

    delete[] arr;
    return 0;
}