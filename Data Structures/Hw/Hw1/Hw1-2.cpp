// HW0.cpp : 定義主控台應用程式的進入點。
//

#include "pch.h"
#include <stdio.h>
#include <string>
#include "iostream"

using namespace std;

struct Node {
	int item;
	struct Node *next;
};

Node* insert(Node* headPtr, int item) {
	Node *prePtr = nullptr, *nowPtr = headPtr;
	
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = nullptr;

	while (nowPtr != nullptr && nowPtr->item < item) {
		prePtr = nowPtr;
		nowPtr = nowPtr->next;
	}

	newNode->next = nowPtr;

	if (prePtr == nullptr)
		return newNode;
	else
		prePtr->next = newNode;

	return headPtr;
}

Node* remove(Node* headPtr, int item) {
	Node *prePtr = nullptr, *nowPtr = headPtr;
	Node *delPtr = nullptr;

	while (nowPtr != nullptr) {
		if (nowPtr->item == item) {
			if (prePtr == nullptr) {
				headPtr = nowPtr->next;
				delPtr = nowPtr;
				nowPtr = nowPtr->next;
			}
			else {
				prePtr->next = nowPtr->next;
				delPtr = nowPtr;
				nowPtr = prePtr->next;
			}

			delete delPtr;
		}
		else {
			prePtr = nowPtr;
			nowPtr = nowPtr->next;
		}
	}

	return headPtr;
}

void display(Node* headPtr) {
	Node* nowPtr = headPtr;

	while (nowPtr != nullptr) {
		printf(" %d", nowPtr->item);
		nowPtr = nowPtr->next;
	}

	printf("\n");
}

int main() {
	string s;
	int t;
	Node* headPtr = nullptr;

	while (true) {
		cout << "Input or Delete? ";
		cin >> s;
		if (s[0] == 'i' || s[0] == 'I') {
			cout << "Input an integer? ";
			cin >> t;
			headPtr = insert(headPtr, t);
		}
		else if (s[0] == 'd' || s[0] == 'D') {
			cout << "Input an integer? ";
			cin >> t;
			headPtr = remove(headPtr, t);
		}
		display(headPtr);
	}

	return 0;
}
