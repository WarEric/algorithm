#include<iostream>
#include<climits>
#include"CutRod.h"
using std::vector;

int CutRod::cut(vector<int> &res, vector<int> &solution, int n)
{
	if(n > p.size()-1 ) 
		return N_OVERFLOW_PRICE_RANGE;
	int v = recursive(n);
	
	res.clear();
	solution.clear();
	for(int i = 0; i <= n; i++)
	{
		res.push_back(r[i]);
		solution.push_back(s[i]);
	}

	return v;
}

int CutRod::recursive(int n)
{
	int q;
	if(r[n] >= 0) return r[n];

	if(n == 0) 
		q = 0;
	else
	{
		q = INT_MIN;
		for(int i = 1; i <= n; i++)
		{
			int temp = recursive(n-i) + p[i];
			if(q < temp)
			{
				q = temp;
				s[n] = i;
			}
		}
	}
	r[n] = q;
	return q;
}
