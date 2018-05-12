/*
 * 自底向上的钢条切割递归实现，附带备忘机制，
 * 程序会输出最终结果
 * by wareric@163.com
 * 2018-05-10
 */
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include"CutRodB2T.h"
#define LINE 8
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::setw;
using std::right;
using std::left;

void printRS(vector<int> &r, vector<int> &s, int n);


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

	CutRodB2T cut(price);
	vector<int> r, s;

	int res, n;
	cout << "input the length: ";
	cin >> n;

	res = cut.cut(r, s, n);
	if(res == N_OVERFLOW_PRICE_RANGE)
		cout << n <<" over the price range" << endl;
	else
		cout << "the maxminum price of " << n << " is " << res << endl;
	printRS(r, s, n);

	return 0;
}

void printRS(vector<int> &r, vector<int> &s, int n)
{
	int len = r.size() < n ? r.size() : n;
	len  = len < s.size() ? len : s.size();
	if(len == 0){
	       cout << "r[] and s[] is empty because cut don't dynamic run" << endl;	
	       return;
	}
	cout << endl;

	int line = LINE;
	int i = 0, j = 0, k = 0;
	for(; i <= len; i++)
	{
		if(8 == line)
			cout << left << setw(4) << "i";
		cout << right << setw(4) << i;
		line--;

		if(line == 0)
		{
			cout << endl;
			line = 8;
			
			cout << "r[i]";
			for(; j <= i; j++)
				cout << right << setw(4) << r[j];
			cout << endl;
			
			cout << "s[i]";
			for(; k <= i; k++)
				cout << right << setw(4) << s[k];
			cout << endl;
			cout << endl;
		}
	}
	i--;

	cout << endl;
	cout << "r[i]";
	for(; j <= i; j++)
		cout << right << setw(4) << r[j];
	cout << endl;
			
	cout << "s[i]";
	for(; k <= i; k++)
		cout << right << setw(4) << s[k];
	cout << endl;
	cout << endl;
}
