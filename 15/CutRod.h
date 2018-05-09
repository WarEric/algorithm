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

class CutRod{
	public:
		CutRod(const std::vector<int> &price): p(price), s(p.size(), 0), r(p.size(), INT_MIN){}

		int cut(std::vector<int> &res, std::vector<int> &solution,int n);
	private:
		int recursive(int n);
		const std::vector<int> &p;
		std::vector<int> s;	
		std::vector<int> r;
};
#endif
