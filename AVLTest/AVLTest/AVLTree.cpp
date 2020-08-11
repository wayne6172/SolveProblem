#include "pch.h"
#include "AVLTree.h"

#ifndef _AVLTREE
#define _AVLTREE

template<class DataType>
AVLNode<DataType>* AVLTree<DataType>::insert(DataType data, bool &success, AVLNode<DataType>* p,
	AVLNode<DataType>* pp, AVLNode<DataType>* gp) {
	AVLNode<DataType>* newNode;

	if (p == nullptr) {
		newNode = new AVLNode<DataType>(data);
		success = true;

		return newNode;
	}
	else if (pp == nullptr) {
		if (p->getData() == data)return p;
		else if (data < p->getData()) {
			p
		}
	}
	else if (gp == nullptr) {

	}
	else {

	}
}

template<class DataType>
AVLNode<DataType>* AVLTree<DataType>::remove(DataType data, bool &success ) {
	return nullptr;
}

template<class DataType>
AVLTree<DataType>::AVLTree() : headPtr(nullptr){
}

template<class DataType>
AVLTree<DataType>::~AVLTree() {
}

template<class DataType>
void AVLTree<DataType>::insert(DataType data) {
	bool success = false;

	headPtr = this->insert(data, success, headPtr , nullptr, nullptr);

}

template<class DataType>
void AVLTree<DataType>::remove(DataType data) {
	bool success = false;

	headPtr = this->remove(data, success);


}

template<class DataType>
bool AVLTree<DataType>::search(DataType data) {
	return false;
}

#endif