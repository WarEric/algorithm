/*
 * 自顶向下的钢条切割递归实现，附带备忘机制，
 * 程序会输出最终结果
 * by wareric@163.com
 * 2018-05-09
 */
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "input should be " << argv[0] << " file.data " << endl;
		exit(EXIT_FAILURE);
	}
	ifstream input(argv[1]);

	vector<int> price;
	int data;
	while(input >> data)
		price.push_back(data);
	input.close();
}

void printv(vector<int> &r; vector<int> &s, int n)
{
	int len = r.size() < n ? r.size() : n;
	len  = len < s.size() ? len : s.size();

	int line = 8;
	int j = 0, k = 0, cout = 0;
	for(int i = 0,  ; i < len; i++)
	{
		if(8 == line)
			cout << left << setw(5) << "i";
		cout << left << setw(4) << i;
		line--;

		if(line == 0)
		{
			cout << endl;
			line = 8;
			cout << left << setw(5) << "r[i]";
			for(; j <= i; j++)
			{
				cout << left << setw(4) << r[i];
			}
		}
		for(; j < i-j; j++)
		{
			if
		}	
	}
}
