#ifndef B_TREE_NODE_HPP
#define B_TREE_NODE_HPP


#include <iostream>
using namespace std;

template<typename T>
class BinaryTreeNode {
	T value;
	BinaryTreeNode<T> *left_child;
	BinaryTreeNode<T> *right_child;
	BinaryTreeNode<T> *parent; 
public:

	BinaryTreeNode(): left_child(NULL), right_child(NULL), value(0){}
	BinaryTreeNode(T val) : left_child(NULL), right_child(NULL)
	{
		value =  val;
	}
	~BinaryTreeNode()
	{
		if (left_child != NULL) delete left_child;
		if (right_child != NULL) delete right_child;
	}

	void setLeft(BinaryTreeNode<T>* n)
	{
		left_child = n;
	}
	void setRight(BinaryTreeNode<T>* n)
	{
		right_child = n;
	}
	void setValue(T val)
	{
		value = val;
	}
	void setParent(BinaryTreeNode<T>* n)
	{
		parent = n;
	}
	T getValue() const {return value;}
	BinaryTreeNode<T>* getLeftNode() {return left_child;}
	BinaryTreeNode<T>* getRightNode() {return right_child;}
	BinaryTreeNode<T>* getParent() {return parent;}
};



#endif
