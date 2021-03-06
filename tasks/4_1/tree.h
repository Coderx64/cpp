#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED



#endif // TREE_H_INCLUDED

#include <iostream>
#include <cstdio>
using namespace std;

struct ttree
{
	int inf;
	ttree *left, *right;
};

ttree *tree;
FILE *f = fopen("input.txt", "r");


void create(int n, ttree *&tr)
{
	int a;
	if(n > 0)
	{
		tr = new ttree;
		fscanf(f, "%d", &a);
		tr -> inf = a;
		tr -> left = tr -> right = NULL;
		int nl = n / 2, nr = n - nl - 1;
		create(nl, tr -> left);
		create(nr, tr -> right);
	}
}



void search1(int x, ttree *tr1, int &code)
{
	if(tr1)
		if(x == tr1 -> inf)
		{
			printf("%d\n",tr1 -> inf);
			code = 1;
		}
		else
		{
			search1(x, tr1 -> left, code);
			search1(x, tr1 -> right, code);
		}
}
void search(int x, ttree *tr)
{
		int code = 0;
		search1(x, tr, code);
		if(!code)
			printf("no");
}

/*void search1(int x, ttree * tr1)
{

if(tr1)
		if(x == tr1 -> inf)
		{
			printf("%d\n",tr1 -> inf);
			code = 1;
		}
		else
		{
			search1(x, tr1 -> left, code);
			search1(x, tr1 -> right, code);
		}
}*/

int height(ttree *tr1)
{
    if(tr1 == 0)
        return 0;
    int l, r;
    if (tr1 -> left != NULL) {
        l = height(tr1 -> left);
    }else
        l = -1;
    if (tr1 -> right != NULL) {
        r = height(tr1 -> right);
    }else
        r = -1;
    int max = l > r ? l : r;
    return max+1;

}

int get(ttree *tr,int n,int c, int k)
{
	if(n == c)
		return 1;
	if(c == k)
	{
		printf("%d\n",tr -> inf);
		return 0;
	}
	return ((tr->left)?get(tr->left,n,c+1, k):0) + ((tr->right)?get(tr->right,n,c+1, k):0);
}

void lvl(ttree *tr, int k)
{
  int t = 0, l = 0;
    while((l = get(tr, t++, 0, k)) != 0)
	{

	}
}

void out(ttree *tr, unsigned k)
{

  if (tr != NULL)
   {
    out(tr->left, k + 3);

    for(unsigned i = 0; i < k; i++)
    {
      cout <<"  ";
    }
     cout << tr->inf << endl;
     out(tr->right, k + 3);
    }

}
