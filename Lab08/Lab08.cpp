// Joshua Matthews
// compile $ clang++ -std=c++11 Lab08.cpp -o Lab08
// run $ ./Lab08
#include "RBTree.hpp"

int main(int argc, const char * argv[])
{

	auto tree = new RBTree<int>();
	cout<<"Insert "<<0<<endl;
	tree->insertNode(0);
	cout<<"Insert "<<1<<endl;
	tree->insertNode(1);
	cout<<"Insert "<<2<<endl;
	tree->insertNode(2);
	cout<<"Insert "<<3<<endl;
	tree->insertNode(3);
	cout<<"Insert "<<4<<endl;
	tree->insertNode(4);
	cout<<"Insert "<<5<<endl;
	tree->insertNode(5);
	cout<<"Insert "<<6<<endl;
	tree->insertNode(6);
	cout<<"Insert "<<7<<endl;
	tree->insertNode(7);
//	auto five_node = tree->searchNode(5);
//	cout<<"Searched for 5, function returned = "<<five_node->getValue()<<endl;
//	auto zero_node = tree->searchNode(0);
//	cout<<"Searched for 0, function returned = "<<zero_node->getValue()<<endl;
//	
//	cout<<"Deleting Node 5"<<endl;
//	tree->deleteNode(5);
//	cout<<"Deleting Node 0"<<endl;
//	tree->deleteNode(0);
	cout<<"Printing tree: "<<endl;
	tree->printTree();
	cout<<endl;
	delete tree;
	return 0;
}
