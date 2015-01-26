#include <iostream>
#include <cstdio>
#include <queue>
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

queue<ttree*> pushed;
ttree *prt;

void add(int x, ttree *&tt)
{
    if (!tt)
    {
        tt=new ttree;
        tt->inf = x;
        tt->left =NULL;
        tt->right = NULL;
        pushed.push(tt->left);
        pushed.push(tt->right);
    }else
    {
        while (!pushed.empty())
        {
            prt = pushed.front();
            pushed.pop();
            add(x,tt->left);
            prt= pushed.front();
            add(x, tt->right);
        }
    }
    /*}else if (!tt->left)
    {
        cout<<"L"<<x<<endl;
        add(x, tt->left);
    }
    else if (!tt->right)
    {
        cout<<"R"<<x<<endl;
        add(x, tt->right);
        //cout<<"R"<<endl;
    }*/
    //cout<<x<<" "<<tt->inf<<endl;
}

void createbin(int n, ttree *&tr)
{
    FILE *f = fopen("input.txt","r");
    int a;
    while (!feof(f))
    {
        fscanf(f,"%d", &a);
        add(a,tr);
        //cout<<a<<endl;
    }
}

void searchD(ttree *tr1)
{
	if(tr1){
        printf("%d\n",tr1 -> inf);
        searchD(tr1 -> left);
        searchD(tr1 -> right);
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
