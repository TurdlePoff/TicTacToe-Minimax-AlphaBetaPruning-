#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int* int_array = 0;
	int num_els;
	int i;

	cout << "Enter the number of Elements you want in the array: ";
	cin >> num_els;

	// Allocate the required memory while program is running.
	int_array = new int[num_els];

	// Check to see if the allocation succeeded.
	if (int_array == 0)
	{
		cout << "Freestore allocation failed" << endl;
		int iTemp;
		cin >> iTemp;
		return (0);
	}

	// Populate the array.
	for (i = 0; i < num_els; ++i)
	{
		cout << "enter element: ";
		cin >> int_array[i];
	}

	// Display the contents of the array.
	for (i = 0; i < num_els; ++i)
	{
		cout << "Element " << i << " is " << *(int_array + i) << endl;
	}

	// Release the allocated memory back to OS.
	delete[] int_array;

	_getch();
}