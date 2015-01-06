// 2.3list.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include "list.h"
#include <fstream>
#include <string>

using namespace std;

const int n = 5;
tlist *h, *t, *h2, *t2;
fstream out("output.txt", ios_base::out);

void sort()
{
	int tmp;
	for(int i = 0; i < n; i++)
	{
		tmp = find_max(h, t);
		remove(h, t, tmp);
		add_t(h2, t2, tmp);
		out << tmp << " ";
	}

}

int main()
{
	init_list(h, t);
	init_list(h2, t2);

    fstream in("input.txt", ios_base::in);
	int tmp;
	for(int i = 0; i < n; i++)
	{
		in >> tmp; 
		add_t(h, t, tmp);
	}

	sort();

	print_list(h2, t2);

	system("pause");
}
