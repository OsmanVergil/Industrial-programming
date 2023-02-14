#include "figure.cpp"
#include <iostream>

using namespace std;

int main() {
    float x1,x2,x3,x4;
    float y1,y2,y3,y4;

    cout << "Insert 1st figure parameters:";
    cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
    Figure figure1(x1,x2,x3,x4,y1,y2,y3,y4);

    cout << "Insert 2nd figure parameters:";
    cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
    Figure figure2(x1,x2,x3,x4,y1,y2,y3,y4);

    cout << "Insert 3rd figure parameters:";
    cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
    Figure figure3(x1,x2,x3,x4,y1,y2,y3,y4);

    Figure mas[] = {figure1, figure2, figure3};
    for (int i = 0; i < 3; i++) {
        cout << "Figure " << i + 1 << ':' << endl;
        mas[i].show();
        cout << "It's ";
        mas[i].is_prug() == 1 ? cout << "rectangle" : cout << "not rectangle"; 
        cout << endl;
        cout << "It's ";
        mas[i].is_square() == 1 ? cout << "square" : cout << "not square"; 
        cout << endl;
        cout << "It's ";
        mas[i].is_romb() == 1 ? cout << "romb" : cout << "not romb"; 
        cout << endl;
        mas[i].is_in_circle() == 1 ? cout << "Can " : cout << "Can't ";
        cout << "circumscribe a circle"; 
        cout << endl;
        mas[i].is_out_circle() == 1 ? cout << "Can " : cout << "Can't ";
        cout << "inscribe a circle"; 
        cout << endl << endl;
    }

    return 0;
}