#include <iostream>
#include <conio.h>

using namespace std;

enum E8Data
{
	E8_TEXT,
	E8_FLOAT,
	E8_INTEGER
};

void Example8(E8Data _eDataType, void* _pData)
{
	switch (_eDataType)
	{
		case E8_TEXT:
		{
			//Do an operation particular for the const char* data type
			cout << "Text: " << reinterpret_cast<const char*>(_pData);
			break;
		}
		case E8_FLOAT:
		{
			float* pFloat = reinterpret_cast<float*> (_pData);

			//Do an operation particular for the float data type
			cout << "Float: " << *pFloat;
			break;
		}
		case E8_INTEGER:
		{
			int* pInt = reinterpret_cast<int*> (_pData);

			//Do an operation particular for the integer data type
			cout << "Integer: " << *pInt;
			break;
		}
		default:
		{
			cout << "Unknown Data Type.";
			break;
		}
	}
	cout << endl;
}

void Example6(const float* _pFloat)
{
	//This removes the const from the float, allowing it to be changed!
	float* pNonConst = const_cast<float*>(_pFloat);

	*pNonConst = 47.47f;

	//This line would not compile:
	//*_pFloat = 47.47f;
}

int main()
{
	//Example 1: Convert from a less precise type to a more precise type
	//No conversion problems
	char c = 65;
	short s = c;
	cout << "char c [Set to 65] = " << c << endl;
	cout << "short s [Set to c] = " << s << endl;

	//Example 2: Convert from a more precise integer to a less precise,
	//Integer wrapping occurs because the char's largest values is 255,
	//therefore it wraps to 0
	unsigned char uc = 256;
	cout << "unsigned char uc [Set to 256] = " << uc << endl;
	cout << "unsigned char uc [Set to 256] cast to int = " << (int)uc;
	cout << endl;

	//Example 3: Convert from a float to an int, the float's calue is truncated
	//at the point of assignment
	int integer = 123456.789f;
	cout << "int integer [Set to 123456.789f] = " << integer << endl;

	//Example 4: Convert from an int to a float
	float real = integer;
	cout << "float real [Set to integer] = " << real << endl;

	//Exampe 5: static_cast an integer to a float
	//Results in no warning from the compiler!
	float real2 = static_cast<float>(integer);
	cout << "float real [Set to integer] with static_cast = " << real2;
	cout << endl;

	//Example 6: const_cast, removal of constness!
	const float fPI = 3.14f;
	cout << fPI << endl;
	Example6(&fPI);
	//Now check the value of fPI!
	cout << fPI << endl;

	//Example 7: C Style Cast
	float realCStyle = (float)integer;
	//Note there is no compiler warning for the above line!

	//Example 8: reinterpret_cast
	int iTest = 50;
	float fTest = 55.5f;
	char cString[] = "Hello";

	void* pVoid = 0;
	pVoid = reinterpret_cast<void*>(&iTest);
	//Note there is no compiler warning for the above line!
	Example8(E8_INTEGER, pVoid);
	
	pVoid = reinterpret_cast<void*>(&fTest);
	Example8(E8_FLOAT, pVoid);

	pVoid = reinterpret_cast<void*>(&cString);
	Example8(E8_TEXT, pVoid);


	_getch();
}