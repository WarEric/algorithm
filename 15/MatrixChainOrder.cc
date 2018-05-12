/*
 * MatrixChain中函数order的实现
 * by wareric@163.com
 * 2018-05-11
 */
#include<climits>
#include<vector>
#include"MatrixChainOrder.h"
using std::vector;

void MatrixChainOrder::order(const vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s)
{
	int n = p.size() - 1;
	for(int i = 0; i < n; i++)
		m[i][i] = 0;
	for(int l = 2; l <= n; l++)
	{
		for(int i = 1; i <= n-l+1; i++)
		{
			int j = i + l - 1;
			m[i-1][j-1] = INT_MAX;
			for(int k = i; k <= j - 1; k++)
			{
				int q = m[i-1][k-1] + m[k+1-1][j-1] + p[i-1] * p[k] * p[j];
				if(q < m[i-1][j-1])
				{
					m[i-1][j-1] = q;
					s[i-1][j-1] = k;
				}
			}
		}
	}
}
