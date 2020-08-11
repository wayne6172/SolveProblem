#pragma once
#include "AVLNode.h"
template<class DataType>
class AVLTree {
private:
	AVLNode<DataType> *headPtr;
	AVLNode<DataType> *insert(DataType, bool &, AVLNode<DataType>*, AVLNode<DataType>*, AVLNode<DataType>*);
	AVLNode<DataType> *remove(DataType, bool &);
public:
	AVLTree();
	~AVLTree();
	void insert(DataType);
	void remove(DataType);
	bool search(DataType);

};

