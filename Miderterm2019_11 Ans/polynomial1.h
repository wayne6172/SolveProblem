//#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 30 /*size of terms array*/

class PolynomialTerm {
public:
	int coef;
	int expo;
};

class ArrayPolynomial {
public:
	PolynomialTerm terms[MAX_TERMS];

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(int coef, int expo) {
		// modify the following code and add your code here
		int i = 0;

		for (; terms[i].coef != 0 && i < MAX_TERMS; i++);

		terms[i].coef = coef;
		terms[i].expo = expo;

		return;
	}

	void printArrayBasedPoly() {
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

		return;
	}

	void showArrayBasedPolyMaxTerm() {
		PolynomialTerm term = findArrayBasedPolyMaxTerm(0);

		if (term.coef == 0)
			return;

		if (term.expo == 0)
			cout << term.coef;
		else
			cout << term.coef << "X^" << term.expo;
	}

	PolynomialTerm findArrayBasedPolyMaxTerm(int i) {
		PolynomialTerm term;

		if (terms[i].coef == 0)return terms[i];

		term = findArrayBasedPolyMaxTerm(i + 1);

		if (term.expo > terms[i].expo)
			return term;
		else if (term.expo == terms[i].expo)
			return term.coef > terms[i].coef ? term : terms[i];

		return terms[i];
	}

	void ArrayBasedRotateTerms() {
		if (terms[0].coef == 0)return;

		PolynomialTerm term = terms[0];

		int i = 0;
		while (terms[i].coef != 0) {
			terms[i] = terms[i + 1];
			i++;
		}

		terms[i - 1] = term;
	}

	void compactCopy(ArrayPolynomial &poly) {
		int poly_now = 0, i, j;
		clear();

		while (poly.terms[poly_now].coef != 0) {
			i = 0;
			while (terms[i].coef != 0 && terms[i].expo > poly.terms[poly_now].expo)
				i++;

			if (terms[i].expo == poly.terms[poly_now].expo) {
				if (terms[i].coef + poly.terms[poly_now].coef == 0) {
					for (int k = i; terms[k].coef; k++)
						terms[k] = terms[k + 1];
				}
				else terms[i].coef += poly.terms[poly_now].coef;
			}
			else {
				j = i;
				for (; terms[j].coef != 0; j++);

				for (; j != i; j--)
					terms[j] = terms[j - 1];

				terms[i] = poly.terms[poly_now];
			}

			poly_now++;
		}

	}
};

class LinkedPolynomialTerm {
public:
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr;
};

class LinkedPolynomial {
public:
	LinkedPolynomialTerm *polynomialTermPtr = nullptr;

	void clear() {
		LinkedPolynomialTerm *tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputTerms(int coef, int expo) {
		LinkedPolynomialTerm *tmpPtr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = polynomialTermPtr;

		polynomialTermPtr = tmpPtr;

		// add your code here 


		return;
	}

	void printLinkBasedPoly() {
		LinkedPolynomialTerm *termPtr = polynomialTermPtr;

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

	void showLinkBasedPolyMaxTerm() {
		LinkedPolynomialTerm *termPtr = findLinkBasedPolyMaxTerm(polynomialTermPtr);

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;
	}

	LinkedPolynomialTerm* findLinkBasedPolyMaxTerm(LinkedPolynomialTerm *currPtr) {

		if (currPtr == nullptr || currPtr->nextTermPtr == nullptr)
			return currPtr;

		LinkedPolynomialTerm *max = findLinkBasedPolyMaxTerm(currPtr->nextTermPtr);

		if (max->expo > currPtr->expo)
			return max;
		else if (max->expo == currPtr->expo)
			return max->coef > currPtr->coef ? max : currPtr;

		return currPtr;
	}

	void LinkBasedRotateTerms() {
		if (polynomialTermPtr == nullptr || polynomialTermPtr->nextTermPtr == nullptr)
			return;

		LinkedPolynomialTerm *newTail = polynomialTermPtr;
		polynomialTermPtr = polynomialTermPtr->nextTermPtr;
		newTail->nextTermPtr = nullptr;

		LinkedPolynomialTerm *currPtr = polynomialTermPtr;
		while (currPtr->nextTermPtr != nullptr)
			currPtr = currPtr->nextTermPtr;

		currPtr->nextTermPtr = newTail;
	}

	void compactCopy(LinkedPolynomial &poly) {
		clear();

		LinkedPolynomialTerm *copyNow = poly.polynomialTermPtr;
		LinkedPolynomialTerm *currPtr, *prePtr;
		LinkedPolynomialTerm *newNode;

		while (copyNow) {
			prePtr = nullptr;
			currPtr = polynomialTermPtr;
			newNode = new LinkedPolynomialTerm;
			newNode->coef = copyNow->coef;
			newNode->expo = copyNow->expo;
			newNode->nextTermPtr = nullptr;
			
			while (currPtr != nullptr && currPtr->expo > newNode->expo) {
				prePtr = currPtr;
				currPtr = currPtr->nextTermPtr;
			}

			if (currPtr == nullptr || currPtr->expo != newNode->expo) {		//插入
				if (prePtr == nullptr)
					polynomialTermPtr = newNode;
				else
					prePtr->nextTermPtr = newNode;

				newNode->nextTermPtr = currPtr;
			}
			else {			//相加或刪除
				if (currPtr->coef + newNode->coef == 0) {
					if (prePtr == nullptr)
						polynomialTermPtr = polynomialTermPtr->nextTermPtr;
					else
						prePtr->nextTermPtr = currPtr->nextTermPtr;
					delete currPtr;
				}
				else currPtr->coef += newNode->coef;
				
				delete newNode;
			}

			copyNow = copyNow->nextTermPtr;
		}

	}
};
