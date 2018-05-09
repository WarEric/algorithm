/*
 * 自顶向下钢条切割类
 * by wareric@163.com
 * 2018-05-09
 */
#ifndef CUTROD_H_
#define CUTROD_H_
#include<vector>
#include<climits>
#define N_OVERFLOW_PRICE_RANGE -1
using std::vector;

class CutRod{
	public:
		CutRod(const vector<int> &price): p(price), s(p.size(), 0), r(p.size(), INT_MIN){}

		int cut(vector<int> &res, vector<int> &solution,int n);
	private:
		int recursive(int n);
		const vector<int> &p;
		vector<int> s;	
		vector<int> r;
};
#endif
