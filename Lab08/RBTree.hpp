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
		while (n != NULL && n->getParent() != NULL && n->getParent()->getColor() == red)
		{
			if (n->getParent()->getParent() == NULL)break;
			if (n->getParent() == n->getParent()->getParent()->getLeftNode())
			{
				auto y = n->getParent()->getParent()->getRightNode();
				if (y != NULL && y->getColor() == red)
				{
					n->getParent()->setColor(black);
					y->setColor(black);
					n->getParent()->getParent()->setColor(red);
					n = n->getParent()->getParent();
				}
				else
				{

					if (n == n->getParent()->getRightNode())
					{
						n = n->getParent();
						this->left_rotate(n,data);
					}
					n->getParent()->setColor(black);
					n->getParent()->getParent()->setColor(red);
					this->right_rotate(n->getParent()->getParent(),data);
				}
			}
			else
			{
				auto y = n->getParent()->getParent()->getLeftNode();
				if (y != NULL && y->getColor() == red)
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
					this->left_rotate(n->getParent()->getParent(),data);
				}
				
			}
		}
		this->getHead()->setColor(black);
	}

	void left_rotate(RBNode<T>* n, T data)
	{
		auto y = n->getRightNode();
		if (y == NULL)return;
		n->setRight(y->getLeftNode());
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
	}

	void right_rotate(RBNode<T>* n, T data)
	{
		auto y = n->getLeftNode();
		if (y == NULL)return;
		n->setLeft(y->getRightNode());
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
	}
};

#endif
