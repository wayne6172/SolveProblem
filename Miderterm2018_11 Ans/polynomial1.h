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

		cout << " + ";
		if (terms[i].expo == 0)
			cout << terms[i].coef;
		else
			cout << terms[i].coef << "X^" << terms[i].expo;

		printArrayBasedPolyRecursively(i + 1);

	}

	void ArrayBasedDifferentiation()
	{
		int i = 0, j;
		while(terms[i].coef != 0) {
			if(terms[i].expo != 0) {
				terms[i].coef *= terms[i].expo--;
				i++;
			}
			else {
				j = i;
				while (terms[j].coef != 0) {
					terms[j].coef = terms[j + 1].coef;
					terms[j].expo = terms[j + 1].expo;
					j++;
				}
			}
		}
	}

	void compactCopy(ArrayPolynomial &poly)
	{
		int i = 0, j, k;

		while(poly.terms[i].coef != 0) {
			j = 0;
			while (terms[j].coef != 0 && terms[j].expo > poly.terms[i].expo)j++;
			if(terms[j].expo == poly.terms[i].expo) {		//add
				if(terms[j].coef + poly.terms[i].coef == 0) {			//delete
					while(terms[j].coef != 0) {
						terms[j].coef = terms[j + 1].coef;
						terms[j].expo = terms[j + 1].expo;
						j++;
					}
				}
				else terms[j].coef += poly.terms[i].coef;
			}
			else {									//insert
				k = j;
				while (terms[k].coef != 0)k++;
				while (k != j) {
					terms[k].coef = terms[k - 1].coef;
					terms[k].expo = terms[k - 1].expo;
					k--;
				}
				terms[j].coef = poly.terms[i].coef;
				terms[j].expo = poly.terms[i].expo;
			}

			i++;
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
	LinkedPolynomialTerm * polynomialTermPtr = nullptr;

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

		cout << " + ";
		if (currPtr->expo == 0)
			cout << currPtr->coef;
		else
			cout << currPtr->coef << "X^" << currPtr->expo;

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
		LinkedPolynomialTerm *currPtr = polynomialTermPtr, *prePtr = nullptr;

		while(currPtr != nullptr) {
			if(currPtr->expo != 0) {
				currPtr->coef *= currPtr->expo--;
				prePtr = currPtr;
				currPtr = currPtr->nextTermPtr;
			}
			else {
				if(prePtr == nullptr) {
					polynomialTermPtr = currPtr->nextTermPtr;
					delete currPtr;
					currPtr = polynomialTermPtr;
				}
				else {
					prePtr->nextTermPtr = currPtr->nextTermPtr;
					delete currPtr;
					currPtr = prePtr->nextTermPtr;
				}
			}
		}

	}

	void compactCopy(LinkedPolynomial &poly)
	{
		LinkedPolynomialTerm *currPtr = poly.polynomialTermPtr;

		while (currPtr != nullptr) {
			LinkedPolynomialTerm *thisCurrPtr = polynomialTermPtr, *thisPrePtr = nullptr;
			LinkedPolynomialTerm *tmpPtr = new LinkedPolynomialTerm;
			tmpPtr->expo = currPtr->expo;
			tmpPtr->coef = currPtr->coef;
			tmpPtr->nextTermPtr = nullptr;

			while(thisCurrPtr != nullptr && thisCurrPtr->expo > currPtr->expo) {
				thisPrePtr = thisCurrPtr;
				thisCurrPtr = thisCurrPtr->nextTermPtr;
			}

			if(thisPrePtr == nullptr) {		//head
				if(thisCurrPtr == nullptr) polynomialTermPtr = tmpPtr;		//nothing
				else {
					if(thisCurrPtr->expo == currPtr->expo) {		//add
						if(thisCurrPtr->coef + currPtr->coef == 0) {		//delete head
							polynomialTermPtr = thisCurrPtr->nextTermPtr;
							delete thisCurrPtr;
						}
						else {
							thisCurrPtr->coef += currPtr->coef;
						}
					}
					else {				//head insert
						tmpPtr->nextTermPtr = thisCurrPtr;
						polynomialTermPtr = tmpPtr;
					}
				}
			}
			else if(thisCurrPtr == nullptr) {		//tail, if this true that you can't find same expo
				thisPrePtr->nextTermPtr = tmpPtr;		//tail insert
			}
			else {				//mid
				if (thisCurrPtr->expo == currPtr->expo) {		//add
					if (thisCurrPtr->coef + currPtr->coef == 0) {		//delete mid node
						thisPrePtr->nextTermPtr = thisCurrPtr->nextTermPtr;
						delete thisCurrPtr;
					}
					else {
						thisCurrPtr->coef += currPtr->coef;
					}
				}
				else {				//mid insert
					tmpPtr->nextTermPtr = thisCurrPtr;
					thisPrePtr->nextTermPtr = tmpPtr;
				}
			}
			
			currPtr = currPtr->nextTermPtr;
		}


		/*
		 while(poly.terms[i].coef != 0) {
			j = 0;
			while (terms[j].coef != 0 && terms[j].expo > poly.terms[i].expo)j++;
			if(terms[j].expo == poly.terms[i].expo) {		//add
				if(terms[j].coef + poly.terms[i].coef == 0) {			//delete
					while(terms[j].coef != 0) {
						terms[j].coef = terms[j + 1].coef;
						terms[j].expo = terms[j + 1].expo;
						j++;
					}
				}
				else terms[j].coef += poly.terms[i].coef;
			}
			else {									//insert
				k = j;
				while (terms[k].coef != 0)k++;
				while (k != j) {
					terms[k].coef = terms[k - 1].coef;
					terms[k].expo = terms[k - 1].expo;
					k--;
				}
				terms[j].coef = poly.terms[i].coef;
				terms[j].expo = poly.terms[i].expo;
			}

			i++;
		}
		 */
	}
};
