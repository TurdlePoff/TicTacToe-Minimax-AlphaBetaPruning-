#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	char Greetings1[] = { 'H', 'E', 'L', 'L', 'O', ' ',
						  'W', 'O', 'R', 'L', 'D', '\0' };
	char BadBuffer[] = { 'B', 'A', 'D', ' ', 'B', 'U', 'F', 'F', 'E', 'R' };
	char Greetings2[] = { "HELLO WORLD" };

	char dest1a[20];
	char dest1b[20];
	char dest1c[20];

	char dest2a[20];
	char dest2b[20];
	char dest2c[20];

	char dest3[100];
	char dest4[5];

	int iBadBuffer = sizeof(BadBuffer);
	int iGreeting1 = sizeof(Greetings1);
	int iGreeting2 = sizeof(Greetings2);

	// Step through the program starting from the next line
	// and examine what happens to the buffers.
	// Example copying char by char definition.
	strcpy(dest1a, Greetings1);
	strncpy(dest1b, Greetings1, 5);
	strncpy(dest1c, Greetings1, 20);

	// Example copying shorthand definition
	strcpy(dest2a, Greetings2);
	strncpy(dest2b, Greetings2, 5);
	strncpy(dest2c, Greetings2, 20);

	// Buffer overrun!!!
	strcpy(dest3, BadBuffer);

	// Buffer overrun!!!
	strcpy(dest4, Greetings1);

	_getch();
}