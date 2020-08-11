#pragma once
template<class DataType>
class AVLNode {
private:
	DataType data;
	AVLNode<DataType> *leftChild, *rightChild;
	int balanceFactor;
public:
	AVLNode(DataType);
	~AVLNode();
	AVLNode<DataType> *getLeft();
	AVLNode<DataType> *getRight();
	DataType getData();
	int getBalance();
	void setLeft(AVLNode<DataType>*);
	void setRight(AVLNode<DataType>*);
	void setData(DataType);
	void setBalance(int);
};

