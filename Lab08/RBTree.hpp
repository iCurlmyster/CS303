#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "BinaryTree.hpp"
#include "RBNode.hpp"

template<typename T>
class RBTree : public BinaryTree<T,RBNode<T>> {

public:
	RBTree(){}
	~RBTree(){}
	void rb_insert_fixup(RBNode<T>* n, T data)
	{
		while (n->getParent() != NULL && n->getParent()->getColor() == red && n != NULL)
		{
			cout<<"Inside while loop rb_insert_fixup"<<endl;
			if (n->getParent() == NULL) break;
			if (n->getParent()->getParent() == NULL)break;
			if (n->getParent() == n->getParent()->getParent()->getLeftNode())
			{
				cout<<"Inside if statement rb_insert_fixup"<<endl;
				auto y = n->getParent()->getParent()->getRightNode();
				if(y == NULL)break;
				if (y->getColor() == red)
				{
					cout<<"In getColor if rb_insert_fixup"<<endl;
					n->getParent()->setColor(black);
					y->setColor(black);
					n->getParent()->getParent()->setColor(red);
					n = n->getParent()->getParent();
					cout<<"exit getColor if rb_insert_fixup"<<endl;
				}
				else
				{

					cout<<"in getColor else rb_insert_fixup"<<endl;
					if (n == n->getParent()->getRightNode())
					{
						n = n->getParent();
						this->left_rotate(n,data);
					}
					n->getParent()->setColor(black);
					n->getParent()->getParent()->setColor(red);
					this->right_rotate(n,data);
					cout<<"exit getColor else rb_insert_fixup"<<endl;
				}
			}
			else
			{
				auto y = n->getParent()->getParent()->getLeftNode();
				if (y->getColor() == red)
				{
					n->getParent()->setColor(black);
					y->setColor(black);
					n->getParent()->getParent()->setColor(red);
					n = n->getParent()->getParent();
				}
				else
				{
					if (n == n->getParent()->getLeftNode())
					{
						n = n->getParent();
						this->right_rotate(n,data);
					}
					n->getParent()->setColor(black);
					n->getParent()->getParent()->setColor(red);
					this->left_rotate(n,data);
				}
				
			}
		}
		cout<<"Endend while loop rb_insert_fixup"<<endl;
		this->getHead()->setColor(black);
	}

	void left_rotate(RBNode<T>* n, T data)
	{
		cout<<"left_rotate enter"<<endl;
		auto y = n->getRightNode();
		n->setRight(n->getLeftNode());
		if (y->getLeftNode() != NULL)
		{
			y->getLeftNode()->setParent(n);
		}
		y->setParent(n->getParent());
		if (n->getParent() == NULL)
			this->setHead(y);
		else if (n == n->getParent()->getLeftNode())
			n->getParent()->setLeft(y);
		else
			n->getParent()->setRight(y);
		y->setLeft(n);
		n->setParent(y);
		cout<<"left_rotate exit"<<endl;
	}

	void right_rotate(RBNode<T>* n, T data)
	{
		cout<<"right_rotate enter"<<endl;
		auto y = n->getLeftNode();
		n->setLeft(n->getRightNode());
		if (y->getRightNode() != NULL)
		{
			y->getRightNode()->setParent(n);
		}
		y->setParent(n->getParent());
		if (n->getParent() == NULL)
			this->setHead(y);
		else if (n == n->getParent()->getRightNode())
			n->getParent()->setRight(y);
		else
			n->getParent()->setLeft(y);
		y->setRight(n);
		n->setParent(y);
		cout<<"right_rotate exit"<<endl;
	}
};

#endif
