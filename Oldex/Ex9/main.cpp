#include <iostream>
#include <conio.h>

using namespace std;

// Arrow Key Codes
const int g_kiDownArrow = 80;
const int g_kiUpArrow = 72;
const int g_kiLeftArrow = 75;
const int g_kiRightArrow = 77;

int main()
{
	// The _getch function read a single character from the console without
	// echoing the character. It cannot be used to read CTRL+C. 
	// When reading an arrow key, the function must be called twice; 
	// the first call returns 0 or 0xE0, and the second call returns the actual key code.
	bool bActive = true;

	while (bActive)
	{
		cout << "Press an Arrow Key, or press ` to quit!" << endl;

		int iKeyPress = _getch();

		if (iKeyPress != 0 && iKeyPress != 0xE0)
		{
			// Valid Key, but not an arrow key!
			cout << " Not an arrow key!!!" << endl;

			// Was it the quit key?
			if (iKeyPress == '`')
			{
				bActive = false;
			}
		}
		else
		{
			int iCheckForArrowKey = _getch();

			switch (iCheckForArrowKey)
			{
				case g_kiUpArrow:
				{
					cout << " Up Arrow" << endl;
					break;
				}
				case g_kiDownArrow:
				{
					cout << " Down Arrow" << endl;
					break;
				}
				case g_kiLeftArrow:
				{
					cout << " Left Arrow" << endl;
					break;
				}
				case g_kiRightArrow:
				{
					cout << " Right Arrow" << endl;
					break;
				}
			}
		}
		cout << endl;
	}
	_getch();
}