#include <iostream>
using namespace std;

double readNumber()
{
    cout << "Введите число: ";
    double x{};
    cin >> x;
    return x;
}

    char arehmetic()
 {
    cout << "Выберете математическую операцию: +, -, *, /" << endl;
    char math{};
    cin >> math;
    return math;
    }

void result(double x, char math, double y)
{
    double res;
    switch (math) // Условия благодоря которому выполняются вычисления
    {
    case '+':
        res = x + y;
        break;

    case '-':
        res = x - y;
        break;

    case '*':
        res = x * y;
        break;

    case '/':
        if (y != 0)
            res = x / y;

        else
        {
            res = 0;
            cout << "Ошибка: деление на ноль" << endl;
        }
        break;

    default:
        res = 0;
        cout << "Ошибка" << endl;
        break;
    }
    cout << "Ответ: " << x << " " << math << " " << y << " is " << res << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    double x{ readNumber() };
    double y{ readNumber() };
    char math{ arehmetic() };

    result(x, math, y);
    return 0;
}
