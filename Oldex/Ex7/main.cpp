#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
	char buffer[256];
	char s0[256];

	cout << "Enter a string with no spaces: ";
	cin >> s0;

	// Once run, try changing n0 to an int.
	// What behaviour does this change?
	int n0 = 0;
	cout << "Enter a number: ";
	cin >> n0;

	char c0 = '\0';
	cout << "Enter a char: ";
	cin >> c0;

	float f0 = 0.0f;
	cout << "Enter a float: ";
	cin >> f0;

	sprintf(buffer, "s0 = %s, n0 = %d, c0 = %c, f0 = %f", s0, n0, c0, f0);
	cout << buffer << endl;

	// Setting the output size of strings.
	sprintf(buffer, "s0 = %s, n0 = %0.4d, c0 = %c, f0 = %0.8f", s0, n0, c0, f0);
	cout << buffer << endl;

	_getch();
}