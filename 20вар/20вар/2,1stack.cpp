// 2,1stack.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include "stack.h"
#include <fstream>

using namespace std;
const int n = 5;
tstack *s1 = init_stack();

void sort(tstack * s)
{
	tstack *s2 = init_stack();
	int tmp, max = -999;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n - i + 1; j++)
		{			
			tmp = pop(s);
			if(max < tmp)
			{
				if(max > 0)
					push(s2, max);
				max = tmp;
			}
			else
				push(s2, tmp);
		}
		push(s1, max);
		for(int j = 0; j < n - i; j++)
		{
			tmp = pop(s2);
			push(s, tmp);
		}
		max = -999;
	}
	tmp = pop(s);
	push(s1, tmp);
}


int main()
{
	tstack *st = init_stack();
	fstream in("input.txt", ios_base::in);
	fstream out("output.txt", ios_base::out);

	int tmp;
	for(int i = 0; i < n; i++)
	{
		in >> tmp; 
		push(st, tmp);
	}

	sort(st);

	for(int i = 0; i < n; i++)
	{
		tmp = pop(s1);
		out << tmp << " ";
	}
    system("pause");
}
