// Joshua Matthews
// compile $ clang++ -std=c++11 Lab07.cpp -o Lab07
// run $ ./Lab07


#include <iostream>
using namespace std;

template<typename T>
class BinaryTreeNode {
	T value;
	BinaryTreeNode *left_child;
	BinaryTreeNode *right_child;

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
	T getValue() const {return value;}
	BinaryTreeNode<T>* getLeftNode() {return left_child;}
	BinaryTreeNode<T>* getRightNode() {return right_child;}	
};

template<typename T>
class BinaryTree {

	BinaryTreeNode<T> *head;

protected:
	BinaryTreeNode<T>* getNode(BinaryTreeNode<T>* node, T data) const
	{
		if (node == NULL || node->getValue() == data) return node;
		if (data < node->getValue()) return getNode(node->getLeftNode(), data);
		else return getNode(node->getRightNode(), data);
	}

	BinaryTreeNode<T>* replaceNode(BinaryTreeNode<T>* n)
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

	void printOrder(BinaryTreeNode<T>* node) const
	{
		if (node != NULL)
		{
			printOrder(node->getLeftNode());
			cout<<"|"<<node->getValue();
			printOrder(node->getRightNode());
		}
	}

public:
	BinaryTree() : head(NULL){}
	BinaryTree(T h){
		head = new BinaryTreeNode<T>(h);
	}

	~BinaryTree(){ if (head != NULL) delete head;}

	void getHead() const { return head; }
	void insertNode(T data){
		if (head == NULL) {
			head = new BinaryTreeNode<T>(data);
			return;
		}
		auto x = head;
		while (x!=NULL)
		{
			if (data < x->getValue()){
				if (x->getLeftNode() == NULL)
				{
					auto tmp = new BinaryTreeNode<T>(data);
					x->setLeft(tmp); 
					x = NULL;
				}
				else x = x->getLeftNode();
			}
			else {
				if (x->getRightNode() == NULL)
				{
					auto tmp = new BinaryTreeNode<T>(data);
					x->setRight(tmp); 
					x = NULL;
				}
				else x = x->getRightNode();
			}
		} // end While		
	} // end of insertNode
	BinaryTreeNode<T> const * searchNode(T data) const {
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

};



int main(int argc, const char * argv[])
{

	auto tree = new BinaryTree<int>();
	cout<<"Insert "<<5<<endl;
	tree->insertNode(5);
	cout<<"Insert "<<3<<endl;
	tree->insertNode(3);
	cout<<"Insert "<<7<<endl;
	tree->insertNode(7);
	cout<<"Insert "<<2<<endl;
	tree->insertNode(2);
	cout<<"Insert "<<9<<endl;
	tree->insertNode(9);
	cout<<"Insert "<<1<<endl;
	tree->insertNode(1);
	cout<<"Insert "<<4<<endl;
	tree->insertNode(4);
	cout<<"Insert "<<0<<endl;
	tree->insertNode(0);
	auto five_node = tree->searchNode(5);
	cout<<"Searched for 5, function returned = "<<five_node->getValue()<<endl;
	auto zero_node = tree->searchNode(0);
	cout<<"Searched for 0, function returned = "<<zero_node->getValue()<<endl;
	
	cout<<"Deleting Node 5"<<endl;
	tree->deleteNode(5);
	cout<<"Deleting Node 0"<<endl;
	tree->deleteNode(0);
	cout<<"Printing tree: ";
	tree->printTree();
	cout<<endl;
	delete tree;
	return 0;
}
