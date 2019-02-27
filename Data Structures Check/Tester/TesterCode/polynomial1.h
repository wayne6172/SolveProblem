#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

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

	void inputTerms(int coef, int expo)
	{
		// modify the following code and add your code here
		int i = 0;

		for (; terms[i].coef != 0 && i < MAX_TERMS; i++);

		terms[i].coef = coef;
		terms[i].expo = expo;

		return;
	}

	void printArrayBasedPoly()
	{
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

	void printArrayBasedPolyRecursively()
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			cout << terms[0].coef;
		else
			cout << terms[0].coef << "X^" << terms[0].expo;

		printArrayBasedPolyRecursively(1);
	}

	void printArrayBasedPolyRecursively(int i)
	{
		if (terms[i].coef == 0)
			return;

		if (terms[i].expo == 0)
			cout << " + " << terms[i].coef;
		else
			cout << " + "<<terms[i].coef << "X^" << terms[i].expo;

		printArrayBasedPolyRecursively(i+1);
	}

	void ArrayBasedDifferentiation()
	{

		for (int i = 0; i < MAX_TERMS; i++)
		{
			if (terms[i].expo != 0) {
				terms[i].coef *= terms[i].expo;
				terms[i].expo--;
			}
			else {
				terms[i].coef = 0;
			}
		}
		


	}

	void compactCopy(ArrayPolynomial &poly)
	{
		for (int i = 0; i < MAX_TERMS; i++)
		{
			int j = 0;
			for (; j < MAX_TERMS; j++) {
				if (terms[j].expo <= poly.terms[i].expo) break;
			}
			if (terms[j].expo == poly.terms[i].expo) {
				terms[j].coef += poly.terms[i].coef;
				if (terms[j].coef == 0) {
					for (int k = j+1; k < MAX_TERMS; k++)
					{
						terms[k - 1].expo = terms[k].expo;
						terms[k - 1].coef = terms[k].coef;
					}
				}
			}
			else {
				if (poly.terms[i].coef != 0) {
					for (int k = MAX_TERMS - 1; k > j; k--)
					{
						terms[k].expo = terms[k - 1].expo;
						terms[k].coef = terms[k - 1].coef;
					}
					terms[j].expo = poly.terms[i].expo;
					terms[j].coef = poly.terms[i].coef;
				}
			}
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

	void clear()
	{
		LinkedPolynomialTerm *tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputTerms(int coef, int expo)
	{
		LinkedPolynomialTerm *tmpPtr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = polynomialTermPtr;

		polynomialTermPtr = tmpPtr;

		// add your code here 


		return;
	}

	void printLinkBasedPoly()
	{
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

	void printLinkBasedPolyRecursively()
	{
		if (polynomialTermPtr == nullptr)
			return;

		if (polynomialTermPtr->expo == 0)
			cout << polynomialTermPtr->coef;
		else
			cout << polynomialTermPtr->coef << "X^" << polynomialTermPtr->expo;

		printLinkBasedPolyRecursively(polynomialTermPtr->nextTermPtr);
	}

	void printLinkBasedPolyRecursively(LinkedPolynomialTerm *currPtr)
	{
		if (currPtr == nullptr)
			return;

		if (currPtr->expo == 0)
			cout << " + "<< currPtr->coef;
		else
			cout << " + "<<currPtr->coef << "X^" << currPtr->expo;

		printLinkBasedPolyRecursively(currPtr->nextTermPtr);

		


	}

	int computeRecursively(int x)
	{
		return computeRecursively(x, polynomialTermPtr);
	}

	int computeRecursively(int x, LinkedPolynomialTerm *currPtr)
	{


		// add yor code here


		return 0;
	}

	void LinkBasedDifferentiation()
	{
		LinkedPolynomialTerm *currPtr = polynomialTermPtr;
		while (currPtr != nullptr) {
			if (currPtr->expo != 0) {
				currPtr->coef *= currPtr->expo;
				currPtr->expo--;
			}
			if (currPtr->nextTermPtr&&currPtr->nextTermPtr->expo == 0) {
				currPtr->nextTermPtr = nullptr;
				break;
			}
			currPtr = currPtr->nextTermPtr;			
		}
	}

	void compactCopy(LinkedPolynomial &poly)
	{
		LinkedPolynomialTerm *currPtr = poly.polynomialTermPtr,* tmpPtr= polynomialTermPtr,* pre;
		while (currPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			LinkedPolynomialTerm *set = new LinkedPolynomialTerm;
			set->coef = currPtr->coef;
			set->expo = currPtr->expo;
			set->nextTermPtr = nullptr;
			pre = nullptr;
			if (polynomialTermPtr == nullptr) {
				polynomialTermPtr = set;
			}
			else {
				while (tmpPtr!= nullptr&&tmpPtr->expo > set->expo) {
					pre = tmpPtr;
					tmpPtr = tmpPtr->nextTermPtr;
				}
				if (tmpPtr&&tmpPtr->expo == set->expo) {
					tmpPtr->coef += set->coef;
					if (tmpPtr->coef == 0) {
						if (pre == nullptr) polynomialTermPtr = polynomialTermPtr->nextTermPtr;
						else {
							pre->nextTermPtr = tmpPtr->nextTermPtr;
						}
					}
				}
				else {
					if (pre == nullptr) {
						polynomialTermPtr = set;
						set->nextTermPtr = tmpPtr;
					}
					else {
						pre->nextTermPtr = set;
						set->nextTermPtr = tmpPtr;
					}
				}

			}
			currPtr = currPtr->nextTermPtr;
		}


	}
};
