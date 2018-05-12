/*
 * 矩阵链动态分割的测试函数,注意要自己输入矩阵m和n，
 * 同时还要注意m[1,4]实际对应的下标应该是m[0][3];
 * by wareric@163.com
 * 2018-05-12
 */
#include<iostream>
#include<fstream>
#include<vector>
#include"MatrixChainOrder.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ifstream;

void printOrder(vector<vector<int>> &s, int i, int j);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "input should be: " << argv[0] << " datafile" << endl;
		exit(EXIT_FAILURE);
	}

	ifstream in(argv[1]);
	vector<int> p;
	int data;
	while( in >> data)
		p.push_back(data);
	in.close();

	MatrixChainOrder matrix;
	vector<vector<int>> m(p.size()-1, vector<int>(p.size()-1, 0));
	vector<vector<int>> s(p.size()-1, vector<int>(p.size()-1, 0));
	matrix.order(p, m, s);

	cout << "the optimal patterns is following:" << endl;
	printOrder(s, 1, p.size()-1);
	cout << endl;

	return 0;
}

void printOrder(vector<vector<int>> &s, int i, int j)
{
	if(i == j)
		cout << "A" << i;
	else
	{
		cout << "(";
		printOrder(s, i, s[i-1][j-1]);
		printOrder(s, s[i-1][j-1]+1, j);
		cout << ")";
	}
}
