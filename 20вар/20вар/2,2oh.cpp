// 2,2oh.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include "queue.h"
#include <fstream>

using namespace std;
const int n = 5;
tqueue *h, *t;
tqueue *h2, *t2;

void sort(tqueue *&h1, tqueue *&t1)
{
	init_queue(h2, t2);
	int tmp, max = -999;

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n - i + 1; j++)
		{			
			tmp = take(h, t);
			if(max < tmp)
			{
				if(max > 0)
					insert(h, t, max);
				max = tmp;
			}
			else
				insert(h, t, tmp);
		}
		insert(h2, t2, max);
		max = -999;
	}
	tmp = take(h, t);
	insert(h2, t2, tmp);
}

int main()
{
	init_queue(h, t);

    fstream in("input.txt", ios_base::in);
	fstream out("output.txt", ios_base::out);
	int tmp;
	for(int i = 0; i < n; i++)
	{
		in >> tmp; 
		insert(h, t, tmp);
	}

	sort(h, t);

	for(int i = 0; i < n; i++)
	{
		tmp = take(h2, t2);
		out << tmp << " ";
	}
	system("pause");
    return 0;
}
