// 4.1.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;
const int n = 5, maxval = 1000;
int gr[n][n];
int res[n][n];
int *nov;
int d[n], p[n];


void print(int a, int b)
{
	cout << b + 1 << " ";
	if(p[b] != a)
		print(a, p[b]);
	else
		cout << a + 1 << " ";
}

int main()
{
    fstream in("input.txt", ios_base::in);
	nov = new int [n];

	for(int i = 0; i < n; i++)
	{
		nov[i] = 1;
		for(int j = 0; j < n; j++)
		{
			in >> gr[i][j];
			if(gr[i][j] == 0)
				gr[i][j] = maxval;
			cout << gr[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << endl;

	//int k = 4;
	//cin >> k;
	//k--;
	for(int k = 0; k < n; k++)
	{
		nov = new int [n];
		for(int i = 0; i < n; i++)
			d[i] = 0;
		int min, w;
		nov[k] = 0;
		for(int i = 0; i < n; i++)
			if(i != k)
			{
				d[i] = gr[k][i];
				p[i] = k;
			}
		for(int i = 1; i < n; i++)
		{
			min = maxval;
			for(int j = 0; j < n; j++)
				if(nov[j] && min > d[j])
				{
					min = d[j];
					w = j;
				}
			nov[w] = 0;
			for(int j = 0; j < n; j++)
				if(nov[j] && d[j] > d[w] + gr[w][j])
				{
					d[j] = d[w] + gr[w][j];
					p[j] = w;
				}
		}


		for(int i = 0; i < n; i++)
			if(i != k)
			{
				cout << i + 1 << " = " << d[i] << " ";
				if(d[i] != maxval && gr[i][k] != maxval)
					res[k][i] = d[i] + gr[i][k];
				if(d[i] != maxval)
				{
					cout << i + 1 << " ";
					if(p[i] != k)
						print(k, i);
					cout << endl;
				}
				else
					cout << endl;
			}
		cout << endl;
	}
	cout << endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	
	system("pause");
}
