/*
 * 自底向上切分函数的实现
 * by wareric@163.com
 * 2018-05-10
 */
#include<vector>
#include<climits>
#include"CutRodB2T.h"
using std::vector;

int CutRodB2T::cut(vector<int> &res, vector<int> &solution, int n)
{
	res.clear();
	solution.clear();
	if(n > p.size()-1)
		return N_OVERFLOW_PRICE_RANGE;

	for(int j = 1; j <= n; j++)
	{
		int q = INT_MIN;
		for(int i = 1; i <= j; i++)
		{
			if(q < p[i]+r[j-i])
			{
				q = p[i]+r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}

	for(int i = 0; i <= n; i++)
	{
		res.push_back(r[i]);
		solution.push_back(s[i]);
	}

	return r[n];
}
