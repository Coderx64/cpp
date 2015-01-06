// 2.3list.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include "tree.h"
#include <fstream>
#include <string>

using namespace std;
int hight = 0, k = 1, l = 0;
string str = "";

struct tstack
{
	ttree *inf; 
	tstack *pr;
};

void pushtr(tstack *&s, ttree *item)
{
	tstack *r = new tstack;
	r -> inf = item;
	r -> pr = s;
	s = r;
}

ttree* pop(tstack *&s)
{
	tstack *r = s;
	ttree *i = r -> inf;
	s = r -> pr;
	delete r;
	return i;
}

void preorder(ttree *tr)
{
	int maxt = 0;
	tstack *s = NULL;
	ttree *m = tr;
	while(true)
		if(m)
		{
			pushtr(s, m);
			k++;
			l++;
			if((m -> left != NULL && m -> right != NULL) || (m -> left == NULL && m -> right == NULL))
			{ 
				if(m -> left == NULL && m -> right == NULL)
					k = k - l;
				l = 0;
			}
			cout << m -> inf   << " " << k << " " << " " << l << endl; 
			if(maxt < k)
				maxt = k;
			m = m -> left;

		}
		else
		{
			if(!s) //стек пуст
				break;
			m = (pop(s)) -> right;
		}
	cout << endl;
	hight = maxt;
	cout << "max hight " <<hight << endl;
	k = 0;
}

void bzzz(ttree *tr)
{
	int maxt = 0, l = 0, l2 = 0, k2 = -1;
	tstack *s = NULL;
	ttree *m = tr;
	l = 0;
	while(true)
		if(m)
		{
			pushtr(s, m);

			str += m -> inf + 48;
			l++;
			if((m -> left != NULL && m -> right != NULL) || (m -> left == NULL && m -> right == NULL))
			{ 
				if(m -> left == NULL && m -> right == NULL)
					if(str.length() < hight)
						str = str.erase(str.length() - l, l);
				l = 0;
			}	
			cout << m -> inf   << " " << str << " " << l << endl; 

			m = m -> left;
		}
		else
		{
			if(!s) //стек пуст
				break;
			m = (pop(s)) -> right;
			/*
			if(m)
				if(m -> left == NULL && m -> right == NULL)
					if(str.length() < hight)
						str = str.erase(str.length() - 1, 1);
						*/
			//cout << m -> inf   << " " << k << " " << endl;
		}
	cout << endl;
	k = 0;
}

int main()
{
	int n, tmp = 0;
    fstream in("input.txt", ios_base::in);
	ttree *tree = NULL;
	in >> n;
	for(int i = 0; i < n; i++)
	{
		in >> tmp;
		push(tmp, tree);
	}
	out(tree, n);

	preorder(tree);
	cout << height(tree)+1 << endl;
	cout << endl;

	bzzz(tree);
	cout << "max path ";
	for(int i = 0; i < str.length(); i++)
		cout << str[i] << " ";
	cout << endl;
	cout << endl;
	system("pause");
}
