#include<iostream>
#include<fstream>
#include"OSTree.h"
using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "input should be: " << string(argv[0]) << " data.txt" << endl;
		return EXIT_FAILURE;
	}
	ifstream input(argv[1]);
	OSTree<int> tree;

	int var;
	while(input >> var)
	{
		if(tree.insert(var) == true)
			cout << "insert "<< var << " successful" << endl;
		else
			cout << "error while insert "<< var << endl;
	}
	input.close();

	cout << "preorderTreeWalk:" << endl;
	tree.preorderTreeWalk();
	cout << "inorderWalkTree:" << endl;
	tree.inorderTreeWalk();
	cout << "postorderWalkTree:" << endl;
	tree.postorderTreeWalk();

	cout << "max = " << (tree.max())->getKey() << endl;
	cout << "min = " << (tree.min())->getKey() << endl;

	OSTNode<int> *x = tree.select(3);
	if(x != OSTree<int>::nil)
		cout << "x = select(3); x->key =  " << x->getKey() << endl;
	cout << "rank(x) = " << tree.rank(x) << endl;


	cout << "After delete 8" << endl;
	tree.del(8);
	cout << "inorderWalkTree:" << endl;
	tree.inorderTreeWalk();

	return 0;
}
