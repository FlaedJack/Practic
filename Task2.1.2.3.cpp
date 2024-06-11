// файл main.cpp
#include <iostream>
#include "io.h"
using namespace std;
int main()
{
	int x = readNumber();
	int y = readNumber();
	
	int sum = x + y;

	writeAnswer(sum);

	return 0;
	}
 
// файл io.cpp
 #include <iostream>
#include "io.h"
using namespace std;
int readNumber()
{
	cout << "Enter an integer: ";
	int x {};
	cin >> x;
	return x;
}
void writeAnswer(int x)
{
	cout << "This number: " << x << endl;
}

//файл io.h
#ifndef IO_H
#define IO_H

int readNumber();
void writeAnswer(int x);

#endif
