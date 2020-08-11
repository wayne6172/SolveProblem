#include "pch.h"
#include "AVLNode.h"

#ifndef _AVLNODE
#define _AVLNODE

template<class DataType>
AVLNode<DataType>::AVLNode(DataType _data) : data(_data), balanceFactor(0) , leftChild(nullptr),
	rightChild(nullptr) {


}

template<class DataType>
AVLNode<DataType>::~AVLNode() {
}

template<class DataType>
AVLNode<DataType>* AVLNode<DataType>::getLeft() {
	return this->leftChild;
}

template<class DataType>
AVLNode<DataType>* AVLNode<DataType>::getRight() {
	return this->rightChild;
}

template<class DataType>
DataType AVLNode<DataType>::getData() {
	return this->data;
}

template<class DataType>
int AVLNode<DataType>::getBalance() {
	return this->balanceFactor;
}

template<class DataType>
void AVLNode<DataType>::setLeft(AVLNode<DataType>* node) {
	this->leftChild = node;
}

template<class DataType>
void AVLNode<DataType>::setRight(AVLNode<DataType>* node) {
	this->rightChild = node;
}

template<class DataType>
void AVLNode<DataType>::setData(DataType data) {
	this->data = data;
}

template<class DataType>
void AVLNode<DataType>::setBalance(int n) {
	this->balanceFactor = n;
}

#endif