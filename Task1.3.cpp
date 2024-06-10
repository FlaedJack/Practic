#include <iostream>

using namespace std;

int getValueFormUser()
{
	cout << "Введите число: ";
	int input{};
	cin >> input;
	return input;
}

int main()
{
	setlocale(LC_ALL, "RU"); // Подключение русского языка 
	int x{ getValueFormUser() };
	int y{ getValueFormUser() };
	cout << x << " + " << y << " = " << x + y << endl;
	return 0;
}
