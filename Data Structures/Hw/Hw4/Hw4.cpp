// HW4.cpp : 定義主控台應用程式的進入點。
//

#include "pch.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

typedef struct {
	int coef;
	int expo;
} polynomialTerm;

typedef struct linkedTerm {
	int coef;
	int expo;
	linkedTerm *nextTermPtr;
} linkedPolynomialTerm;

void clear(polynomialTerm t[]) {
	for (int i = 0; i < MAX_TERMS; i++) {
		t[i].coef = 0;
		t[i].expo = 0;
	}

	return;
}

void clear(linkedPolynomialTerm *&polynomialTermPtr) {
	linkedPolynomialTerm *tmpPtr;

	while (polynomialTermPtr != nullptr) {
		tmpPtr = polynomialTermPtr;
		polynomialTermPtr = polynomialTermPtr->nextTermPtr;
		delete tmpPtr;
	}
}

void inputTerms(polynomialTerm terms[], int coef, int expo) {

	// add your code here

	return;
}

void inputLinkTerms(linkedPolynomialTerm *&polyPtr, int coef, int expo) {
	linkedPolynomialTerm *tmpPtr, *curPtr = polyPtr, *prePtr = nullptr;

	tmpPtr = new linkedPolynomialTerm;
	tmpPtr->coef = coef;
	tmpPtr->expo = expo;
	tmpPtr->nextTermPtr = nullptr;

	while (curPtr != nullptr && curPtr->expo > expo) {
		prePtr = curPtr;
		curPtr = curPtr->nextTermPtr;
	}

	if (curPtr != nullptr && curPtr->expo == expo) {			//取代
		if (coef == 0) {										//刪除
			if (prePtr == nullptr)
				polyPtr = curPtr->nextTermPtr;
			else 
				prePtr->nextTermPtr = curPtr->nextTermPtr;
			delete curPtr;
		}
		else curPtr->coef = coef;
	}
	else {														//插入
		if (coef != 0) {
			tmpPtr->nextTermPtr = curPtr;

			if (prePtr == nullptr)
				polyPtr = tmpPtr;
			else
				prePtr->nextTermPtr = tmpPtr;
		}
	}


	return;
}


void addArrayBasedPoly(polynomialTerm a[], polynomialTerm b[], polynomialTerm d[]) {

	// add your code here

	return;
}

linkedPolynomialTerm *addLinkBasedPoly(linkedPolynomialTerm *aPtr, linkedPolynomialTerm *bPtr) {
	linkedPolynomialTerm *dPtr = nullptr, *a = aPtr, *b = bPtr, *tailPtr = nullptr, *newNode;


	while (a != nullptr && b != nullptr) {
		newNode = new linkedPolynomialTerm;
		newNode->nextTermPtr = nullptr;

		if (a->expo > b->expo) {
			newNode->coef = a->coef;
			newNode->expo = a->expo;
			
			a = a->nextTermPtr;
		}
		else if (a->expo < b->expo) {
			newNode->coef = b->coef;
			newNode->expo = b->expo;

			b = b->nextTermPtr;
		}
		else {
			if (a->coef + b->coef == 0) {
				a = a->nextTermPtr;
				b = b->nextTermPtr;
				delete newNode;
				continue;
			}
			else {
				newNode->coef = a->coef + b->coef;
				newNode->expo = a->expo;

				a = a->nextTermPtr;
				b = b->nextTermPtr;
			}
		}

		if (dPtr == nullptr) {
			dPtr = newNode;
			tailPtr = dPtr;
		}
		else {
			tailPtr->nextTermPtr = newNode;
			tailPtr = newNode;
		}
	}

	while (a != nullptr) {
		newNode = new linkedPolynomialTerm;
		newNode->coef = a->coef;
		newNode->expo = a->expo;
		newNode->nextTermPtr = nullptr;

		if (dPtr == nullptr) {
			dPtr = newNode;
			tailPtr = newNode;
		}
		else {
			tailPtr->nextTermPtr = newNode;
			tailPtr = newNode;
		}

		a = a->nextTermPtr;
	}

	while (b != nullptr) {
		newNode = new linkedPolynomialTerm;
		newNode->coef = b->coef;
		newNode->expo = b->expo;
		newNode->nextTermPtr = nullptr;

		if (dPtr == nullptr) {
			dPtr = newNode;
			tailPtr = newNode;
		}
		else {
			tailPtr->nextTermPtr = newNode;
			tailPtr = newNode;
		}

		b = b->nextTermPtr;
	}

	return dPtr;
}

void printArrayBasedPoly(polynomialTerm terms[]) {
	if (terms[0].coef == 0)
		return;

	if (terms[0].expo == 0)
		cout << terms[0].coef;
	else
		cout << terms[0].coef << "X^" << terms[0].expo;

	for (int i = 1; i < MAX_TERMS; i++) {
		if (terms[i].coef == 0)
			return;

		if (terms[i].expo == 0)
			cout << " + " << terms[i].coef;
		else
			cout << " + " << terms[i].coef << "X^" << terms[i].expo;
	}
}

void printLinkBasedPoly(linkedPolynomialTerm *polyPtr) {
	linkedPolynomialTerm *termPtr = polyPtr;

	if (termPtr == nullptr)
		return;

	if (termPtr->expo == 0)
		cout << termPtr->coef;
	else
		cout << termPtr->coef << "X^" << termPtr->expo;

	termPtr = termPtr->nextTermPtr;

	while (termPtr != nullptr) {
		if (termPtr->coef == 0)
			return;

		if (termPtr->expo == 0)
			cout << " + " << termPtr->coef;
		else
			cout << " + " << termPtr->coef << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;
	}
}

int main(int argc, char* argv[]) {
	polynomialTerm a[MAX_TERMS], b[MAX_TERMS], d[MAX_TERMS];
	linkedPolynomialTerm *aPtr, *bPtr, *dPtr;

	int coef, expo;

	aPtr = bPtr = dPtr = nullptr;

	while (1) {
		clear(a); clear(b); clear(d);
		clear(aPtr); clear(bPtr); clear(dPtr);

		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			inputTerms(a, coef, expo);
			inputLinkTerms(aPtr, coef, expo);
		}

		cout << "\n\na = ";
		printArrayBasedPoly(a);
		cout << "\na = ";
		printLinkBasedPoly(aPtr);
		cout << "\n";

		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			inputTerms(b, coef, expo);
			inputLinkTerms(bPtr, coef, expo);
		}

		cout << "\n\nb = ";
		printArrayBasedPoly(b);

		cout << "\nb = ";
		printLinkBasedPoly(bPtr);

		cout << "\n";

		// d =a + b, where a, b, and d are polynomials

		addArrayBasedPoly(a, b, d);
		cout << "\na + b = ";
		printArrayBasedPoly(d);

		dPtr = addLinkBasedPoly(aPtr, bPtr);
		cout << "\na + b = ";
		printLinkBasedPoly(dPtr);

		cout << "\n";
	}
	return 0;
}
