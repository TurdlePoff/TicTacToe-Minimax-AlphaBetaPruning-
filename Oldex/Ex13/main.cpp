#include <iostream>
#include <conio.h>

using namespace std;

// Function prototypes.

void PrintArray(int* array, int size);
int* ResizeArray(int* array, int oldSize, int newSize);

int main()
{
	// Our main array pointer and a variable to keep track of array size.
	int* array = 0;
	int arraySize = 0;

	// Boolean variable to let us know when the user wants to quit.
	bool done = false;

	while (!done)
	{
		// Every loop cycle print the array.
		PrintArray(array, arraySize);

		// Print a menu of options.
		cout << "1) Set Element " << endl;
		cout << "2) Resize Array " << endl;
		cout << "3) Quit " << endl;

		// Get choice.
		int selection = 1;
		cin >> selection;

		// Some vars that will receive additional input deciding
		// on user choice.
		int index = -1;
		int value = 0;
		int newSize = 0;

		// Evaluate the user’s choice.
		switch (selection)
		{
		case 1:
			// Ask for the element the user wants to set.
			cout << "Index = ";
			cin >> index;

			// Make sure index they want to set is within
			// the bounds.
			if (index < 0 || index >= arraySize)
			{
				cout << "Bad Index!" << endl;
			}

			// The array index must be good.
			else
			{
				// Ask the user to input the value they
				// want that element to be set to.
				cout << "[" << index << "] = ";
				cin >> value;

				// Set the value to the index.
				array[index] = value;
			}
				break;
		case 2:
			// Ask the user to enter the size of the new array
			cout << "Size = ";
			cin >> newSize;

			// Call the resize function. This function returns
			// a pointer to the newly resized array.
			array = ResizeArray(array, arraySize, newSize);

			// Update the array size variable.
			arraySize = newSize;
			break;
		default:
			// Cause the loop to terminate.
			done = true;
			break;
		}
	}
	delete[] array;
	array = 0;

	return (0);
}

/**
* - Javadoc in c++ -
* Function that iterates each element in the given array.
*
* @author Not me
* @param array A pointer to the first element of an integer array.
* @param size The number of elements in the array.
*/
void PrintArray(int* array, int size)
{
	// If the array is of size zero than call it a null array.
	if (size < 1)
	{
		cout << "Null Array." << endl;
	}
	else
	{
		// Size of array is > 0, so print each element.
		cout << "{";
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << "}" << endl;
	}
	return;
}

/**
*
* Returns a new array given the new size.
*
* @param array A pointer to the first element of an integer array.
* @param oldSize The number of elements currently in 'array'.
* @param newSize The number of elements we want in the array.
*
*/
int* ResizeArray(int* array, int oldSize, int newSize)
{
	// Create an array with the new size.
	int* newArray = new int[newSize];

	// The new array is a greater size than the old one.
	if (newSize >= oldSize)
	{
		// Copy old elements to new array.
		for (int i = 0; i < oldSize; ++i)
		{
			newArray[i] = array[i];
		}
	}
	// New array is a lesser size than old array.
	else
	{
		// Copy as many old elements to new arrays as can fit.
		for (int i = 0; i < newSize; ++i)
		{
			newArray[i] = array[i];
		}
	}

	// Delete the old array.
	delete[] array;
	array = 0;

	// Return a pointer to the new array.
	return (newArray);
}