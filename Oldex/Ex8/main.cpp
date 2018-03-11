#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	// Convert a real number in the form of
	// a string literal, into a double.
	double dNum = atof("47.47");
	cout << "dNum: " << dNum << endl;

	// Convert a whole number in the form of
	// a string literal, into an integer.
	int iNum = atoi("156");
	cout << "iNum: " << iNum << endl;

	//Test using char arrays...
	char test1[] = { '1', '2', '.', '3', '4', '\0' };
	char test2[] = { '1', '2', '3', '4', '\0' };

	//Convert char arrays into numbers...
	double dTest1 = atof(test1);
	int iTest2 = atoi(test2);
	cout << "dTest: " << dTest1 << endl;
	cout << "iTest: " << iTest2 << endl;

	_getch();
}