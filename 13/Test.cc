/*
 * 测试红黑树实现是否正确的测试代码.
 *
 * by wareric@163.com
 * 2018-04-06
 */
#include<iostream>
#include"Node.h"
#include"RBTree.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	RBTree T;
	int x;
	cout << "Please input your numbers which are splitted by blank.\n"
		<< "There should be no repeate numbers.\n:";
	while(cin >> x)
		rbInsertKey(&T, x);

	cout << "\nShow the tree we build by inorder wolk" << endl;
	inorderTreeWalk(T.root, T.getNil());
	
	return 0;
}
