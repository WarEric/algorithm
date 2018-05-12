/*
 * interval tree 的测试函数，仅仅验证新增的功能，并不测试所有的
 * by wareric@163.com
 * 2018-05-04
 */
#include<iostream>
#include<fstream>
#include"ITVTree.h"
using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "input should be: " << string(argv[0]) << " data.txt" << endl;
		return EXIT_FAILURE;
	}
	ifstream input(argv[1]);
	ITVTree<int> tree;

	int var1, var2;
	while(input >> var1 && input >> var2)
	{
		if(tree.insert(var1, var2) == true)
			cout << "insert ["<< var1 << " , "<< var2 << "] successful" << endl;
		else
			cout << "error while insert  ["<< var1 << " , "<< var2 << "]" << endl;
	}
	input.close();

	cout << "preorderTreeWalk:" << endl;
	tree.preorderTreeWalk();
	cout << "inorderWalkTree:" << endl;
	tree.inorderTreeWalk();
	cout << "postorderWalkTree:" << endl;
	tree.postorderTreeWalk();

	cout << "max = [" << (tree.max())->getLow() << " , " << (tree.max())->getHigh() << "]" << endl;
	cout << "min = [" << (tree.min())->getLow() << " , " << (tree.min())->getHigh() << "]" << endl;

	ITVNode<int> *x = tree.search(8, 9);
	if(x != ITVTree<int>::nil)
	{
		cout << "x = search(8, 9); x =  [" << x->getLow() << " , " << x->getHigh() << "]" << endl;
		cout << "After delete x" << endl;
		tree.del(x);
		delete x;
		cout << "preorderTreeWalk:" << endl;
		tree.preorderTreeWalk();
		cout << "inorderWalkTree:" << endl;
		tree.inorderTreeWalk();
		cout << "postorderWalkTree:" << endl;
		tree.postorderTreeWalk();
	}

	return 0;
}
