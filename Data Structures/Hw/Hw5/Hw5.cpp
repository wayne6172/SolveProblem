// HW5.cpp : 定義主控台應用程式的進入點。
//

#include "pch.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm {
public:
	int coef;
	int expo;
};                                                                          /////

class ArrayPolynomial {                                        /////
public:                                                                  /////
	PolynomialTerm terms[MAX_TERMS]; /////

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(int coef, int expo) /////
	{

		int i, j;

		for (i = 0; terms[i].coef != 0 && terms[i].expo > expo; i++);


		if (terms[i].expo == expo) {		//取代
			if (coef == 0) {
				for (j = i; terms[j].coef != 0; j++)
					terms[j] = terms[j + 1];
			}
			else terms[i].coef = coef;
		}
		else {							//加入
			if (coef != 0) {
				for (j = 0; terms[j].coef != 0; j++);
				while (j != i) {
					terms[j] = terms[j - 1];
					j--;
				}

				terms[i].coef = coef;
				terms[i].expo = expo;
			}
		}

		return;
	}

	void addArrayBasedPoly(ArrayPolynomial &a, ArrayPolynomial &b) /////
	{

		int i, j, k;
		i = j = k = 0;

		while (a.terms[i].coef != 0 && b.terms[j].coef != 0) {
			if (a.terms[i].expo > b.terms[j].expo)
				terms[k++] = a.terms[i++];
			else if (a.terms[i].expo < b.terms[j].expo)
				terms[k++] = b.terms[j++];
			else {
				if (a.terms[i].coef + b.terms[j].coef != 0) {
					terms[k].coef = a.terms[i].coef + b.terms[j].coef;
					terms[k].expo = a.terms[i].expo;
					k++;
				}

				i++, j++;
			}
		}

		while (a.terms[i].coef != 0)
			terms[k++] = a.terms[i++];

		while (b.terms[j].coef != 0)
			terms[k++] = b.terms[j++];

		return;
	}

	void reverseArrayBasedPoly() /////
	{
		int j;
		for (j = 0; terms[j].coef != 0; j++);
		j--;

		PolynomialTerm t;
		for (int i = 0; i < j; i++, j--) {
			t = terms[i];
			terms[i] = terms[j];
			terms[j] = t;
		}


		return;
	}

	void printArrayBasedPoly() /////
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			std::cout << terms[0].coef;
		else
			std::cout << terms[0].coef << "X^" << terms[0].expo;

		for (int i = 1; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				std::cout << " + " << terms[i].coef;
			else
				std::cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}

	int compute(int x) {
		int sum = 0;
		for (int i = 0; terms[i].coef != 0; i++) 
			sum += terms[i].coef * pow(x, terms[i].expo);


		return sum;
	}
};

class LinkedPolynomialTerm {
public:
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr; /////
};                                                                  /////

class LinkPolynomial {                                /////
public:                                                          /////
	LinkedPolynomialTerm *polynomialTermPtr = nullptr; /////

	void clear() /////
	{
		LinkedPolynomialTerm *tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputLinkTerms(int coef, int expo) /////
	{
		LinkedPolynomialTerm *tmpPtr, *curPtr = polynomialTermPtr, *prePtr = nullptr;

		tmpPtr = new LinkedPolynomialTerm;
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
					polynomialTermPtr = curPtr->nextTermPtr;
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
					polynomialTermPtr = tmpPtr;
				else
					prePtr->nextTermPtr = tmpPtr;
			}
		}


		return;
	}

	void addLinkBasedPoly(LinkPolynomial &aPol, LinkPolynomial &bPol) /////
	{
		LinkedPolynomialTerm *a = aPol.polynomialTermPtr, 
			*b = bPol.polynomialTermPtr, *tailPtr = nullptr, *newNode;


		while (a != nullptr && b != nullptr) {
			newNode = new LinkedPolynomialTerm;
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

			if (polynomialTermPtr == nullptr) {
				polynomialTermPtr = newNode;
				tailPtr = polynomialTermPtr;
			}
			else {
				tailPtr->nextTermPtr = newNode;
				tailPtr = newNode;
			}
		}

		while (a != nullptr) {
			newNode = new LinkedPolynomialTerm;
			newNode->coef = a->coef;
			newNode->expo = a->expo;
			newNode->nextTermPtr = nullptr;

			if (polynomialTermPtr == nullptr) {
				polynomialTermPtr = newNode;
				tailPtr = newNode;
			}
			else {
				tailPtr->nextTermPtr = newNode;
				tailPtr = newNode;
			}

			a = a->nextTermPtr;
		}

		while (b != nullptr) {
			newNode = new LinkedPolynomialTerm;
			newNode->coef = b->coef;
			newNode->expo = b->expo;
			newNode->nextTermPtr = nullptr;

			if (polynomialTermPtr == nullptr) {
				polynomialTermPtr = newNode;
				tailPtr = newNode;
			}
			else {
				tailPtr->nextTermPtr = newNode;
				tailPtr = newNode;
			}

			b = b->nextTermPtr;
		}

	}

	void reverseLinkBasedPoly() /////
	{
		if (polynomialTermPtr == nullptr)return;

		LinkedPolynomialTerm *curPtr = nullptr ,
			*prePtr = nullptr, *nextPtr = polynomialTermPtr;

		while (nextPtr != nullptr) {
			prePtr = curPtr;
			curPtr = nextPtr;
			nextPtr = nextPtr->nextTermPtr;

			curPtr->nextTermPtr = prePtr;
		}

		polynomialTermPtr = curPtr;

		return;
	}

	void printLinkBasedPoly()                                                            /////
	{
		LinkedPolynomialTerm *termPtr = polynomialTermPtr; /////

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

		return;
	}

	int compute(int x) {

		int sum = 0;

		LinkedPolynomialTerm *curPtr = polynomialTermPtr;

		while (curPtr != nullptr) {
			sum += curPtr->coef * pow(x, curPtr->expo);
			curPtr = curPtr->nextTermPtr;
		}


		return sum;
	}
};

int main(int argc, char* argv[]) {
	ArrayPolynomial a, b, d;                                                              /////
	LinkPolynomial aPol, bPol, dPol;                                             /////

	int coef, expo, x;

	// aPtr = bPtr = dPtr = nullptr; /////

	while (1) {
		a.clear(); b.clear(); d.clear();                                    /////
					  // aPtr->clear(aPtr); bPtr->clear(bPtr); dPtr->clear(dPtr); /////


		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			a.inputTerms(coef, expo);             /////
			aPol.inputLinkTerms(coef, expo); /////
		}

		cout << "\n\na = ";
		a.printArrayBasedPoly();     /////
		cout << "\na = ";
		aPol.printLinkBasedPoly(); /////
		cout << "\n";

		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			b.inputTerms(coef, expo);             /////
			bPol.inputLinkTerms(coef, expo); /////
		}

		cout << "\n\nb = ";
		b.printArrayBasedPoly();      /////

		cout << "\nb = ";
		bPol.printLinkBasedPoly(); /////

		cout << "\n";

		// d =a + b, where a, b, and d are polynomials

		d.addArrayBasedPoly(a, b); /////
		cout << "\na + b = ";
		d.printArrayBasedPoly();     /////

		dPol.addLinkBasedPoly(aPol, bPol); /////
		cout << "\na + b = ";
		dPol.printLinkBasedPoly();               /////

		cout << "\n";

		d.reverseArrayBasedPoly(); /////
		cout << "\nreversed d = ";
		d.printArrayBasedPoly();     /////

		dPol.reverseLinkBasedPoly(); /////
		cout << "\nreversed d = ";
		dPol.printLinkBasedPoly();               /////

		cout << "\n";

		cout << "\ninput X: ";
		cin >> x;

		cout << "\nd = ";
		cout << d.compute(x);      //////

		cout << "\nd = ";
		cout << dPol.compute(x); //////

		cout << "\n";

		aPol.clear(); bPol.clear(); dPol.clear(); /////
	}

	return 0;
}
