// HW0.cpp : 定義主控台應用程式的進入點。
//

#include "pch.h"
#include <stdio.h>
#include <string>
#include "iostream"

using namespace std;

int insert(int data[], int target, int count) {
	int i;

	for (i = 0; i < count && data[i] < target; i++);

	for (int j = count; j != i; j--)
		data[j] = data[j - 1];

	data[i] = target;
	return count + 1;
}

int remove(int data[], int target, int count) {
	int i;
	
	for (i = 0; i < count; ) {
		if (data[i] == target) {
			for (int j = i; j < count; j++)
				data[j] = data[j + 1];

			count--;
		}
		else i++;
	}

	return count;
}

void display(int data[], int count) {
	for (int i = 0; i < count; i++)
		printf(" %d", data[i]);
	printf("\n");
}

int main() {
	string s;
	int t;
	int data[10000], count = 0;

	while (true) {
		cout << "Input or Delete? ";
		cin >> s;
		if (s[0] == 'i' || s[0] == 'I') {
			cout << "Input an integer? ";
			cin >> t;
			count = insert(data, t, count);
		}
		else if (s[0] == 'd' || s[0] == 'D') {
			cout << "Input an integer? ";
			cin >> t;
			count = remove(data, t, count);
		}
		display(data, count);
	}

	return 0;
}
