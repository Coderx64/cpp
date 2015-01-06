// 2.3list.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include "three.h"
#include <fstream>

using namespace std;

int main()
{
	int n, k = 0, h = 0;
    fstream in("input.txt", ios_base::in);
	fscanf(f, "%d", &n);
	ttree *tree = NULL;
	create(n, tree);
	out(tree, n);
	//search(k, tree);
	//cout << height(tree) << endl;
	cout << "lvl ";
	cin >> k;
	lvl(tree, k - 1);
	system("pause");
}
