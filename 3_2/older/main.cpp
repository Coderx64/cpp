#include <iostream>
#include "tree.h"
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    fstream in("input.txt", ios_base::in);
	fscanf(f, "%d", &n);
	//cout<<n<<endl;
	ttree *tree = NULL;
	ttree *x = NULL;
	ttree *y = NULL;
	createbin(15, tree);
    //createbin(n, x);
    //Обход в ширину
    //http://algolist.manual.ru/ds/walk.php
    searchD(tree);

   return 0;
    queue<ttree*> q;
    queue<ttree*> p;

    q.push(tree);
    p.push(x);

    while (! q.empty())
    {
        x = q.front();
        q.pop();
        cout<<x->inf<<" ";
        /*y= p.front();
        p.pop();*/
        //search1(x->inf, tree,x->inf);
        /*if (x->inf == y->inf)
        {
            cout<<x->inf<<" = "<<y->inf<<endl;
        }
        else
        {
            cout<<x->inf<<" != "<<y->inf<<endl;
        }*/

        if (x->left != NULL)
        {
            q.push(x->left);
        }

        /*if (y->left !=NULL)
        {
            p.push(y->left);
        }*/

        if (x->right != NULL)
        {
            q.push(x->right);
        }
        /*if (y->right != NULL)
        {
            p.push(y->right);
        }*/
    }

    return 0;
}
