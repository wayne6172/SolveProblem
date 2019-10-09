// HW0.cpp : 定義主控台應用程式的進入點。
//

#include "pch.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

#define MAX 5

struct Node {
	int item;
	Node* next;
};

typedef Node* nodePtr;

Node *inputData(int num, nodePtr headPtr) {
	nodePtr currentPtr = headPtr;

	nodePtr tmpPtr = (nodePtr)malloc(sizeof(Node));
	tmpPtr->item = num;
	tmpPtr->next = NULL;

	if (headPtr == NULL)
		return tmpPtr;
	else {
		while (currentPtr->next != NULL)
			currentPtr = currentPtr->next;

		currentPtr->next = tmpPtr;

		return headPtr;
	}
}

void printArrayForward(int A[]) {
	for (int i = 0; i < MAX; i++)
		printf(" %d", A[i]);
}


void printArrayBackward(int A[], int i) {
	if (i != MAX) {
		printArrayBackward(A, i + 1);
		printf(" %d", A[i]);
	}
}

void printListForward(nodePtr ptr) {
	nodePtr now = ptr;
	while (now != nullptr) {
		printf(" %d", ptr->item);
		now = now->next;
	}
}

void printListBackward(nodePtr ptr) {
	if (ptr != NULL) {
		printListBackward(ptr->next);
		printf(" %d", ptr->item);
	}
}

int main() {
	int num;
	int A[MAX] = { 0 };
	nodePtr headPtr = NULL;

	printf("Input %d numbers: ", MAX);

	for (int i = 0; i < MAX; i++) {
		cin >> num;
		A[i] = num;
		headPtr = inputData(num, headPtr);
	}

	printf("\nArray Forward Iteratively:  ");
	printArrayForward(A);
	printf("\nArray Backward Recursively: ");
	printArrayBackward(A, 0);

	printf("\nList Forward Iteratively:  ");
	printListForward(headPtr);
	printf("\nList Backward Recursively: ");
	printListBackward(headPtr);

	printf("\n");
	system("PAUSE");
	return 0;
}
