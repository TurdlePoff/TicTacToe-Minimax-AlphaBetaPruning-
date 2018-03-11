#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
	//Examine the results of the following program using the debugger
	//and watch window.

	const int iSize = 10;
	char buffer1[iSize];
	char buffer2[iSize];
	char buffer3[iSize];

	//Fill buffer 1, with 'a's
	for (int i = 0; i < iSize; ++i)
	{
		buffer1[i] = 'a';
	}

	//Terminate buffer 1 with the null character.
	buffer1[iSize - 1] = 0;

	//Fill buffer 2 and 3, with zeros.
	for (int i = 0; i < iSize; ++i)
	{
		buffer2[i] = 0;
		buffer3[i] = 0;
	}

	//Copy buffer 1 into buffer 2.
	strcpy(buffer2, buffer1);

	//Copy five characters from buffer 1 into buffer 3.
	strncpy(buffer3, buffer1, 5);

	//Compare buffer 1 and 2, should be identical.
	int iCompare1 = strcmp(buffer1, buffer2);

	//Compare buffer 1 and 3, should be different.
	int iCompare2 = strcmp(buffer1, buffer3);

	//Fill buffer 2, with 'b's
	for (int i = 0; i < iSize; ++i)
	{
		buffer2[i] = 'b';
	}

	//Terminate buffer 2 with the null character.
	buffer2[iSize - 1] = 0;

	//Create a buffer twice the size to demo concatenation.
	char buffer4[iSize * 2];

	//Copy buffer 1 into buffer 4.
	strcpy(buffer4, buffer1);

	//Concatenate buffer 2 with buffer 4.
	strcat(buffer4, buffer2);

	//Find the first 'b' in buffer 4.
	size_t iPosition = strcspn(buffer4, "b");

	//Edit buffer4 to place a substring in the middle.
	buffer4[4] = 't';
	buffer4[5] = 'e';
	buffer4[6] = 's';
	buffer4[7] = 't';

	//Find the address of the start of the substring "test" in buffer4
	char* pStart = strstr(buffer4, "test");

	//Find the number of characters in buffer1
	size_t iBuffer1Length = strlen(buffer1);

	//Find the number of characters in buffer2
	size_t iBuffer2Length = strlen(buffer2);

	//Find the number of characters in buffer3
	size_t iBuffer3Length = strlen(buffer3);

	//Find the number of characters in buffer4
	size_t iBuffer4Length = strlen(buffer4);

	_getch();
}