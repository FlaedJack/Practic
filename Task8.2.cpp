#include <iostream>

using namespace std;

namespace Constants
{
	constexpr double pi{ 3.14159 };
}

using Degrees = double;
using Radians = double;

static Radians convertToRadians(Degrees degrees)
{
	return degrees * Constants::pi / 180;
}

int main()
{
	cout << "Enter a number of degrees: ";
	Degrees degrees{};
	cin >> degrees;

	Radians radians{ convertToRadians(degrees) };
	cout << degrees << " degrees is " << radians << " radians.\n";

	return 0;
}
