#include<iostream>
#include<fstream>
#include"BSTree.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "input should be: " << argv[0] << " data.txt " << endl;
		return EXIT_FAILURE;
	}

	ifstream input(argv[1]);
	BSTree<int> tree;
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

	cout << "please input the number you want to search and delete:___\b\b\b";
	while(cin >> var)
	{
		BSTNode<int> *ptr = tree.search(var);
		if(ptr == nullptr)
			cout  << var << " doesn't exist in the tree." << endl;
		else{
			cout << var << " exists in the tree." << endl;

			BSTNode<int> *pre = tree.predecessor(ptr);
			if(pre == nullptr)
				cout << var << " don't have predecessor" << endl;
			else{
				cout << var << "'s predecessor is " << pre->getKey() << endl;
			}

			BSTNode<int> *suc = tree.successor(ptr);
			if(suc == nullptr)
				cout << var << " don't have successor" << endl;
			else{
				cout << var << "'s successor is " << suc->getKey() << endl;
			}
		}

		if(tree.del(var) == false)
		{
			cout << "error while deleting " << var << endl;
		}else{
			cout << "delete " << var << " success, inorderWalkTree:" << endl;
			tree.inorderTreeWalk();
		}

		cout << "please input the number you want to search and delete:___\b\b\b";
	}
	cout << "\n";


	BSTree<int> cp = tree;
	cout << "copy tree to cp, inorderWalkTree" << endl;
	cp.inorderTreeWalk();

//	cout << "cp == tree : " << (cp == tree) << endl;

	tree.destroy();
	cout << "After tree.destroy(), inorderTreeWalk:" << endl;
	tree.inorderTreeWalk();

	return 0;
	
}
