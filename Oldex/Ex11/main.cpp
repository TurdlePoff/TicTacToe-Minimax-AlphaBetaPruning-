#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int* pInt = 0;
	float* pFloat = 0;
	double* pDouble = 0;

	// Allocate the required memory while program is running.
	pInt = new int;
	pFloat = new float;
	pDouble = new double;

	// Check to see if the allocation succeeded.
	if (pInt == 0 || pFloat == 0 || pDouble == 0)
	{
		cout << "Freestore allocation failed!" << endl;
		int iTemp;
		cin >> iTemp;
		return (0);
	}

	// Populate the variables on the freestore.
	*pInt = 47;
	*pFloat = 147.47f;
	*pDouble = 247.47;

	// Display the contents of pointer and the value on the Freestore.
	cout << "pInt @ " << pInt << " is " << *pInt << endl;
	cout << "pFloat @ " << pFloat << " is " << *pFloat << endl;
	cout << "pDouble @ " << pDouble << " is " << *pDouble << endl;

	// Release the allocated memory back to OS.
	delete pInt;
	delete pFloat;
	delete pDouble;

	// Set the pointers to null to avoid dangling pointer.
	pInt = 0;
	pFloat = 0;
	pDouble = 0;

	_getch();
}