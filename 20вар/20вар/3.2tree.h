#include <iostream>
using namespace std;

struct ttree
{
	int inf; 
	ttree *left, *right;
};

ttree *tree;

void push(int a,ttree *&tr)
{
    if (tr == NULL) 
    {
        tr = new ttree;
        tr -> inf = a; //Кладем в выделенное место аргумент a
        tr -> left = tr -> right = NULL; 
        return; 
    }
        if (a > tr->inf)
			push(a,tr->right); //Если а больше текущего элемента, кладем вправо
        else 
			push(a,tr->left); //Иначе влево

}

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
/*

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
*/
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