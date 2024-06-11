// файл constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    constexpr int max_class_size{ 23 };
}
#endif

// файл main.cpp
#include "constants.h"

#include <iostream>

int main()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;


	if (students > constants :: max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

	return 0;
}
