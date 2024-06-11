#include <iostream>
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	setlocale(LC_ALL, "RU");
	int x = 6;
	int y = 7;

	cout << "До изменения: x = " << x << " y = " << y << endl;
		swap(x, y);
	cout << "После изменения: x = " << x << " y = " << y << endl;

		return 0;
}
