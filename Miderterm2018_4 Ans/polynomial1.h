#include "stdafx.h"
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
		int i = 0, j;
		while (terms[i].coef != 0 && terms[i].expo > expo)i++;

		if (expo == terms[i].expo) {
			if (terms[i].coef + coef == 0) {
				while (terms[i].coef != 0) {
					terms[i].coef = terms[i + 1].coef;
					terms[i].expo = terms[i + 1].expo;
					i++;
				}
			}
			else terms[i].coef += coef;
		}
		else {
			if (coef != 0) {
				j = i;
				while (terms[j].coef != 0)j++;
				while (j != i) {
					terms[j].coef = terms[j - 1].coef;
					terms[j].expo = terms[j - 1].expo;
					j--;
				}
				terms[i].coef = coef;
				terms[i].expo = expo;
			}
		}

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
		if (terms[i].coef != 0) {
			cout << " + ";
			if (terms[i].expo == 0) {
				cout << terms[i].coef;
			}
			else cout << terms[i].coef << "X^" << terms[i].expo;
			printArrayBasedPolyRecursively(i + 1);
		}
	}


	int computeRecursively(int x)
	{
		return computeRecursively(x, 0);
	}

	int computeRecursively(int x, int i)
	{
		int sum = 0;
		if (terms[i].coef != 0) {
			sum = terms[i].coef * (int)pow(x, terms[i].expo);
			sum += computeRecursively(x, i + 1);
		}
		return sum;
	}

	void copy(ArrayPolynomial &poly)
	{
		clear();				//�o�@�B�ڤ��ӲM���O�_�Ӱ��A�p�G���o�򰵡Ab�b�Y�Ǳ��p�Ucopy�|���A�Ա��K��
		int i = 0, j = 0;
		while (poly.terms[i].coef != 0) {
			terms[j].coef = poly.terms[i].coef;
			terms[j].expo = poly.terms[i].expo;
			i++;
			j++;
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
		LinkedPolynomialTerm *tmpPtr,*curPtr = polynomialTermPtr,*prePtr = nullptr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = nullptr;

		while (curPtr != nullptr && curPtr->expo > expo) {
			prePtr = curPtr;
			curPtr = curPtr->nextTermPtr;
		}
		
		if (prePtr == nullptr) {		//�e��
			if (curPtr == nullptr) {
				if (coef != 0)polynomialTermPtr = tmpPtr;		//�L���ͦ�
			}
			else {
				if (curPtr->expo == expo) {
					if (curPtr->coef + coef == 0) {			//�e�ݧR��
						polynomialTermPtr = curPtr->nextTermPtr;
						delete curPtr;
					}
					else {									//�e���л\
						curPtr->coef += coef;
					}
					delete tmpPtr;
				}
				else{							//�e�ݴ��J
					if (coef != 0) {
						polynomialTermPtr = tmpPtr;
						tmpPtr->nextTermPtr = curPtr;
					}
				}
			}
		}
		else if (curPtr == nullptr) {	//��ݡA�q�]�p�޿�ӬݡA���|�o�ͫ�ݧR���M�л\�A�u�����J�A�L���ͦ��b�e���]�z�ﱼ�F
			if (coef != 0) {
				prePtr->nextTermPtr = tmpPtr;
			}
		}
		else{							//����
			if (curPtr->expo == expo) {		
				if (curPtr->coef + coef == 0) {		//���ݧR��
					prePtr->nextTermPtr = curPtr->nextTermPtr;
					delete curPtr;
				}
				else {								//�����л\
					curPtr->coef += coef;
				}
				delete tmpPtr;
			}
			else {				//���ݴ��J
				if (coef != 0) {
					prePtr->nextTermPtr = tmpPtr;
					tmpPtr->nextTermPtr = curPtr;
				}
			}
		}
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
		if (currPtr != nullptr) {
			if (currPtr->expo == 0)
				cout << " + " << currPtr->coef;
			else
				cout << " + " << currPtr->coef << "X^" << currPtr->expo;

			printLinkBasedPolyRecursively(currPtr->nextTermPtr);
		}
	}

	int computeRecursively(int x)
	{
		return computeRecursively(x, polynomialTermPtr);
	}

	int computeRecursively(int x, LinkedPolynomialTerm *currPtr)
	{
		int sum = 0;

		if (currPtr != nullptr) {
			sum = currPtr->coef * (int)pow(x, currPtr->expo);
			sum += computeRecursively(x, currPtr->nextTermPtr);
		}

		return sum;
	}

	void copy(LinkedPolynomial &poly)
	{
		LinkedPolynomialTerm *curPtr = poly.polynomialTermPtr;
		clear();

		LinkedPolynomialTerm *copyPtr;
		while (curPtr != nullptr) {

			LinkedPolynomialTerm *tmpPtr = new LinkedPolynomialTerm;
			tmpPtr->coef = curPtr->coef;
			tmpPtr->expo = curPtr->expo;
			tmpPtr->nextTermPtr = nullptr;

			if (polynomialTermPtr == nullptr) {
				polynomialTermPtr = tmpPtr;
				copyPtr = polynomialTermPtr;
			}
			else {
				copyPtr->nextTermPtr = tmpPtr;
				copyPtr = tmpPtr;
			}
			curPtr = curPtr->nextTermPtr;
		}

	}
};
