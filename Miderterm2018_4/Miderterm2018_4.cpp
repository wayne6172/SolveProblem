// Midterm2018_04.cpp : 定義主控台應用程式的進入點。
//
#include <iostream>
#include <string>
#include <cctype>
#include "polynomial1.h"
#include "BagInterface.h"
#include "ArrayBag.h"
#include "LinkedBag.h"

#define SIZE 10

void input(string sMessage, string &sInputString)
{
	cout << sMessage << endl;
	cin >> sInputString;
	return;
}

void output(string sMessage)
{
	if (sMessage.length() > 0)
		cout << endl << sMessage << endl;

	return;
}

int inputNumber(string sMessage, int A[])
{
	int i;

	for (i = 0; i < SIZE; i++) {
		cout << sMessage;
		cin >> A[i];

		if (A[i] == 0)
			break;
	}

	return i;
}

// ================ Question 1 Begins Here ==================

void	accumulate(int A[], int start, int end)
{


	// add yor code here


	return;
}

void doQ1()
{
	int aArray[SIZE];
	int size = inputNumber("Enter a number (0 to end): ", aArray);

	cout << endl << "Input numbers: ";

	for (int i = 0; i < size; i++)
		cout << aArray[i] << " ";

	accumulate(aArray, 0, size - 1);

	cout << endl << "Accumulation: ";

	for (int i = 0; i < size; i++)
		cout << aArray[i] << " ";

	cout << endl;

	return;
}

// ================ Question 1 Ends Here ==================

// ================ Question 2 Begins Here =================
void doQ2()
{
	ArrayPolynomial aArrPoly, bArrPoly;
	LinkedPolynomial aLinkPol, bLinkPol;

	int coef, expo;

	aArrPoly.clear(); bArrPoly.clear();

	for (int i = 0; i < MAX_TERMS; i++) {
		cout << "\ninput a's coefficient and exponent: ";
		cin >> coef >> expo;

		if (expo == 0 && coef == 0)
			break;

		aArrPoly.inputTerms(coef, expo);

		cout << "\n\na = ";
		aArrPoly.printArrayBasedPoly();
		cout << "\na = ";
		aArrPoly.printArrayBasedPolyRecursively();
		bArrPoly.copy(aArrPoly);
		cout << "\nb = ";
		bArrPoly.printArrayBasedPoly();
		cout << "\na = ";
		cout << aArrPoly.computeRecursively(10);
		cout << "\n";

		aLinkPol.inputTerms(coef, expo);

		cout << "\na = ";
		aLinkPol.printLinkBasedPoly();
		cout << "\na = ";
		aLinkPol.printLinkBasedPolyRecursively();
		bLinkPol.copy(aLinkPol);
		cout << "\nb = ";
		bLinkPol.printLinkBasedPoly();
		cout << "\na = ";
		cout << aLinkPol.computeRecursively(10);
		cout << "\n";
	}
}
// ================ Question 2 Ends Here ==================

// ================ Question 3 Begins Here ==================

void displayBag(ArrayBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize() << " items: ";
	vector<string> bagItems = bag.toVector();
	int numberOfEntries = (int)bagItems.size();

	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}  // end for

	cout << endl;
}  // end displayBag

void bagTester(ArrayBag<string>& bag)
{
	string items[] = { "5E", "1A", "5E", "3C", "5E", "3C", "5E", "3C", "5E", "5E" };
	string otherItems[] = { "1A", "5E", "3C", "2B", "4D" };


	cout << "Add 10 items to the bag: " << endl;

	for (int i = 0; i < 10; i++)
		bag.add(items[i]);

	displayBag(bag);

	for (int i = 0; i < 5; i++)
	{
		bag.remove(otherItems[i]);
		displayBag(bag);
	}

	for (int i = 0; i < 10; i++)
		bag.add(items[i]);

	displayBag(bag);

	ArrayBag<string> anotherBag;

	for (int i = 0; i < 5; i++)
		anotherBag.add(otherItems[i]);

	bag.remove(anotherBag);
	displayBag(bag);

} // end bagTester

void displayBag(LinkedBag<string>* bagPtr)
{
	cout << "The bag contains " << bagPtr->getCurrentSize() << " items: ";
	vector<string> bagItems = bagPtr->toVector();

	int numberOfEntries = (int)bagItems.size();

	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}  // end for

	cout << endl;
}  // end displayBag

void bagTester(LinkedBag<string>* bagPtr)
{
	string items[] = { "5E", "1A", "5E", "3C", "5E", "3C", "5E", "3C", "5E", "5E" };
	string otherItems[] = { "1A", "5E", "3C", "2B", "4D" };

	cout << "Add 10 items to the bag: " << endl;

	for (int i = 0; i < 10; i++)
		bagPtr->add(items[i]);

	displayBag(bagPtr);

	for (int i = 0; i < 5; i++)
	{
		bagPtr->remove(otherItems[i]);
		displayBag(bagPtr);
	}

	for (int i = 0; i < 10; i++)
		bagPtr->add(items[i]);

	displayBag(bagPtr);

	LinkedBag<string>* anotherBagPtr = nullptr;
	anotherBagPtr = new LinkedBag<string>();

	for (int i = 0; i < 5; i++)
		anotherBagPtr->add(otherItems[i]);

	bagPtr->remove(anotherBagPtr);
}  // end bagTester

void doQ3()
{
	char userChoice = ' ';

	while (toupper(userChoice) != 'X') {
		cout << "Enter 'A' to test the array-based implementation\n"
			<< " 'L' to test the link-based implementation or 'X' to exit: ";
		cin >> userChoice;

		if (toupper(userChoice) == 'A')
		{
			ArrayBag<string> bag;
			cout << "Testing the Array-Based Bag:" << endl;
			cout << "The initial bag is empty." << endl;
			bagTester(bag);
		}
		else
		{
			LinkedBag<string>* bagPtr = nullptr;
			bagPtr = new LinkedBag<string>();
			cout << "Testing the Link-Based Bag:" << endl;
			cout << "The initial bag is empty." << endl;
			bagTester(bagPtr);
			delete bagPtr;
			bagPtr = nullptr;
		}  // end if

		cout << "All done!\n\n" << endl;
	}
}

// ================ Question 3 Ends Here ==================

// ============== Main Program Begins Here ================

int main()
{
	string sCommand, sName, sNum, sMessage;

	while (1) {
		cout << endl;
		cout << "1. Recursive function" << endl;
		cout << "2. Polynomial functions" << endl;
		cout << "3. Bag functions" << endl;
		input("Enter Question Number( 1 ~ 3 ) or 0 to Exit:", sNum);

		switch (sNum[0] - '0') {
		case 0:
			return 0;
		case 1:
			doQ1();
			break;
		case 2:
			doQ2();
			break;
		case 3:
			doQ3();
			break;
		}
	}
}

// ============== Main Program Ends Here ================
