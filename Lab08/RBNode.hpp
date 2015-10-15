#ifndef RB_NODE_HPP
#define RB_NODE_HPP
#include "BinaryTreeNode.hpp"
typedef enum color_t {
	red,
	black
}color;

template<typename T>
class RBNode {
	T value;
	RBNode<T> *left_child;
	RBNode<T> *right_child;
	RBNode<T> *parent; 
	color nodeColor;
public:

	RBNode(): left_child(NULL), right_child(NULL), value(0),parent(NULL), nodeColor(red){}
	RBNode(T val) : left_child(NULL), right_child(NULL), nodeColor(red), parent(NULL)
	{
		value =  val;
	}
	~RBNode()
	{
		if (left_child != NULL) delete left_child;
		if (right_child != NULL) delete right_child;
	}

	void setLeft(RBNode<T>* n)
	{
		left_child = n;
	}
	void setRight(RBNode<T>* n)
	{
		right_child = n;
	}
	void setValue(T val)
	{
		value = val;
	}
	T getValue() const {return value;}
	RBNode<T>* getLeftNode() {return left_child;}
	RBNode<T>* getRightNode() {return right_child;}
	RBNode<T>* getParent() {return parent;}
	void setParent(RBNode<T>* n) { parent = n; }
	void setColor(color c) { nodeColor = c; }
	color getColor() const { return nodeColor; }
};

#endif
