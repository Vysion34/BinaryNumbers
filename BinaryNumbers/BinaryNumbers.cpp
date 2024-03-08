// BinaryNumbers.cpp : Defines the entry point for the console application.

/* Dean Hartfield

1-20-2016

Module 03 Activity - Calculating Binary Numbers

Write a computer program in the C language that reads two binary numbers
from the standard input (keyboard) and outputs their sum, difference, and
product (in binary format) to the standard output (monitor).

*/

#include "stdafx.h"
#include <string>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void setConsoleFont() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

// Validate if a string is a binary number
bool IsBinary(string s)
{
	bool binary = true;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s.at(i) != '1' && s.at(i) != '0')
		{
			binary = false;
		}
	}

	return binary;
}

int main()
{
	setConsoleFont();

	const size_t bits = sizeof(long) * CHAR_BIT;

	// Ask the user for the first binary number
	cout << "Enter the 1st binary number: ";
	string firstBinary;
	cin >> firstBinary;

	// Ask the user for the second binary number
	cout << "Enter the 2nd binary number: ";
	string secondBinary;
	cin >> secondBinary;
	
	cout << endl << endl;

	// Check that the user input are valid binary numbers
	if (IsBinary(firstBinary) && IsBinary(secondBinary)) {
		bitset<bits> bs1(firstBinary);
		bitset<bits> bs2(secondBinary);

		// Convert the bitset to an unsigned long int
		unsigned long ulong1 = bs1.to_ulong();
		unsigned long ulong2 = bs2.to_ulong();

		string binStr;

		// Binary sum
		bitset<bits> bsSum(ulong1 + ulong2);
		cout << "Binary sum (" << bits << "-bit)" << ":        " << "0b" << bsSum.to_string() << endl;

		cout << endl;

		// Binary difference
		bitset<bits> bsDiff(ulong1 - ulong2);
		cout << "Binary difference (" << bits << "-bit)" << ": " << "0b" << bsDiff.to_string() << endl;

		cout << endl;

		// Binary product
		bitset<bits> bsProd(ulong1 * ulong2);
		cout << "Binary product (" << bits << "-bit)" << ":    " << "0b" << bsProd.to_string() << endl;
	}
	else {
		cout << "Invalid binary numbers were entered. Please try again." << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
