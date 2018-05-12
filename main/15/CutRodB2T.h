/*
 * 动态规划切割钢条自底向上
 * by wareric@163.com
 * 2018-05-10
 */
#ifndef CUTRODB2T_H_
#define CUTRODB2T_H_
#include<vector>
#define N_OVERFLOW_PRICE_RANGE -1
using std::vector;

class CutRodB2T{
	public:
		CutRodB2T(vector<int> price):p(price), s(p.size(), 0), r(p.size(), 0){}
		int cut(vector<int> &res, vector<int> &solution, int n);
	private:
		vector<int> p;
		vector<int> r;
		vector<int> s;
};
#endif
