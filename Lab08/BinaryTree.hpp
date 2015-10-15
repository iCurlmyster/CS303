#ifndef B_TREE_HPP
#define B_TREE_HPP

#include <iostream>
#include "RBNode.hpp"
using namespace std;

template<typename T, typename NODE = BinaryTreeNode<T>>
class BinaryTree {

	NODE *head;

protected:
	NODE* getNode(NODE* node, T data) const
	{
		if (node == NULL || node->getValue() == data) return node;
		if (data < node->getValue()) return getNode(node->getLeftNode(), data);
		else return getNode(node->getRightNode(), data);
	}

	NODE* replaceNode(NODE* n)
	{
		auto replaceParent = n;
		auto replace = n;
		auto focusNode = n->getRightNode();
		while (focusNode != NULL)
		{
			replaceParent = replace;
			replace = focusNode;
			focusNode = focusNode->getLeftNode();
		}

		if (replace != n->getRightNode())
		{
			replaceParent->setLeft(replace->getRightNode());
			replace->setRight(n->getRightNode()); 
		}
		return replace;
	}

	void printOrder(NODE* node) const
	{
		if (node != NULL)
		{
			printOrder(node->getLeftNode());
			cout<<"|"<<node->getValue()<<":";
			if (node->getColor() == red) cout<<"red";
			else cout<<"black";
			printOrder(node->getRightNode());
		}
	}

public:
	BinaryTree() : head(NULL){}
	BinaryTree(T h){
		head = new NODE(h);
	}

	~BinaryTree(){ if (head != NULL) delete head;}

	NODE* getHead() const { return head; }
	void insertNode(T data){
		if (head == NULL) {
			head = new NODE(data);
			return;
		}
		auto x = head;
		NODE* tmp;
		while (x!=NULL)
		{
			if (data < x->getValue()){
				if (x->getLeftNode() == NULL)
				{
					tmp = new NODE(data);
					tmp->setParent(x);
					x->setLeft(tmp); 
					x = NULL;
				}
				else x = x->getLeftNode();
			}
			else {
				if (x->getRightNode() == NULL)
				{
					tmp = new NODE(data);
					tmp->setParent(x);
					x->setRight(tmp); 
					x = NULL;
				}
				else x = x->getRightNode();
			}
		} // end While
		cout<<"Calling rb_insert_fixup!"<<endl;
		this->rb_insert_fixup(tmp, data);		
	} // end of insertNode
	NODE const * searchNode(T data) const {
		return getNode(head, data);
	}
	void printTree() const { printOrder(head); }
	bool deleteNode(T data)
	{
		auto focusNode = head;
		auto parentNode = head;
		bool isALeftChild = true;
		while (focusNode->getValue() != data)
		{
			parentNode = focusNode;
			if (data < focusNode->getValue())
			{
				isALeftChild = true;
				focusNode = focusNode->getLeftNode();
			}
			else 
			{
				isALeftChild = false;
				focusNode = focusNode->getRightNode();
			}
			if (focusNode == NULL) return false;
		}
		if (focusNode->getLeftNode() == NULL && focusNode->getRightNode() == NULL)
		{
			if (focusNode == head)
			{
				head = NULL;
			}
			else if (isALeftChild)
			{
				parentNode->setLeft(NULL);
			}
			else
			{
				parentNode->setRight(NULL);
			}
		}
		else if (focusNode->getRightNode() == NULL)
		{
			if (focusNode == head)
			{
				head = focusNode->getLeftNode();
			}
			else if (isALeftChild)
			{
				parentNode->setLeft(focusNode->getLeftNode());
			}
			else
			{
				parentNode->setRight(focusNode->getLeftNode());
			}
		}
		else if (focusNode->getLeftNode() == NULL)
		{
			if (focusNode == head)
			{
				head = focusNode->getRightNode();
			}
			else if (isALeftChild)
			{
				parentNode->setLeft(focusNode->getRightNode());
			}
			else
			{
				parentNode->setRight(focusNode->getRightNode());
			}
		}
		else
		{
			auto replacementNode = this->replaceNode(focusNode);
			if (focusNode == head)
			{
				head = replacementNode;
			}
			else if (isALeftChild)
			{
				parentNode->setLeft(replacementNode);
			}
			else
			{
				parentNode->setRight(replacementNode);
			}
			replacementNode->setLeft(focusNode->getLeftNode());
		}
		return true;
	}
	virtual void rb_insert_fixup(NODE* n, T data) {}
	void setHead(NODE* n) {this->head = n;}
};



#endif
