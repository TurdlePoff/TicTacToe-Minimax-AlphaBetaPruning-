#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
	cout << "Non zero results are true..." << endl << endl;

	//Test for alphanumeric.
	cout << "Is 'a' alphanumeric character? " << isalnum('a') << endl;
	cout << "Is '1' alphanumeric character? " << isalnum('1') << endl;
	cout << "Is '%' alphanumeric character? " << isalnum('%') << endl;
	cout << "Is '\\0' alphanumeric character? " << isalnum('\0') << endl;
	cout << endl;

	//Test for alphabetic.
	cout << "Is 'a' alphabetic character? " << isalpha('a') << endl;
	cout << "Is '1' alphabetic character? " << isalpha('1') << endl;
	cout << "Is '%' alphabetic character? " << isalpha('%') << endl;
	cout << "Is '\\0' alphabetic character? " << isalpha('\0') << endl;
	cout << endl;

	//Test for control character.
	cout << "Is 'a' a control character? " << iscntrl('a') << endl;
	cout << "Is '1' a control character? " << iscntrl('1') << endl;
	cout << "Is '%' a control character? " << iscntrl('%') << endl;
	cout << "Is '\\0' a control character? " << iscntrl('\0') << endl;
	cout << endl;

	//Test for digits.
	cout << "Is 'a' a digit character? " << isdigit('a') << endl;
	cout << "Is '1' a digit character? " << isdigit('1') << endl;
	cout << "Is '%' a digit character? " << isdigit('%') << endl;
	cout << "Is '\\0' a digit character? " << isdigit('\0') << endl;
	cout << endl;

	//Test for graphical representation, ie: a char that can be drawn.
	cout << "Is 'a' a graphical character? " << isgraph('a') << endl;
	cout << "Is '1' a graphical character? " << isgraph('1') << endl;
	cout << "Is '%' a graphical character? " << isgraph('%') << endl;
	cout << "Is '\\0' a graphical character? " << isgraph('\0') << endl;
	cout << endl;

	//Test for lowercase characters.
	cout << "Is 'a' a lowercase character? " << islower('a') << endl;
	cout << "Is '1' a lowercase character? " << islower('1') << endl;
	cout << "Is '%' a lowercase character? " << islower('%') << endl;
	cout << "Is '\\0' a lowercase character? " << islower('\0') << endl;
	cout << endl;

	//Test for printable characters.
	cout << "Is 'a' a printable character? " << isprint('a') << endl;
	cout << "Is '1' a printable character? " << isprint('1') << endl;
	cout << "Is '%' a printable character? " << isprint('%') << endl;
	cout << "Is '\\0' a printable character? " << isprint('\0') << endl;
	cout << endl;

	//Test for hexadecimal digits.
	cout << "Is '1' a hexadecimal character? " << isxdigit('1') << endl;
	cout << "Is 'a' a hexadecimal character? " << isxdigit('a') << endl;
	cout << "Is 'g' a hexadecimal character? " << isxdigit('g') << endl;
	cout << "Is '#' a hexadecimal character? " << isxdigit('#') << endl;

	_getch();
}