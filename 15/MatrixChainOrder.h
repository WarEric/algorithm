/*
 * 动态规划计算矩阵链的加括号方式,算法复杂度为O(n^3);
 * by wareric@163.com
 * 2018-05-11
 */
#ifndef MATRIXCHAIN_H_
#define MATRIXCHAIN_H_
#include<vector>
using std::vector;

class MatrixChain{
	public:
		MatrixChain():p(nullptr), m(nullptr), s(nullptr){}
		void order(const vector<int> *p, vector<int> *m, vector<int> *s);
	private:
		const vector<int> *p;
		vector<int> *m;
		vector<int> *s;
};
#endif
