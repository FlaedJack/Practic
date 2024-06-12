#include <iostream>
#include "Header.h"

using namespace std;

void calculate(double height, int time) {
    double heightNow;
    int t = 0;
    while (t <= time) {
        heightNow = height - 0.5 * speedfall * (t * t);
        if (heightNow > 0.0) {
            cout << "Высота падения за " << t << " секунд " << heightNow << endl;
        }
        else {
            cout << "Мяч на земле " << t << " секунд" << endl;
            break;
        }
        t++;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите высоту башни в метрах: ";
    double height{};
    cin >> height;

    calculate(height, 5);

    return 0;
}

// файл Header.h
#pragma
constexpr double speedfall{ 9.8 };

