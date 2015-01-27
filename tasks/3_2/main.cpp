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
	cout<<n<<endl;
	ttree *tree = NULL;
	ttree *x = NULL;
	create(n, tree);
    create(n, x);
    //Обход в ширину
    //http://algolist.manual.ru/ds/walk.php
    queue<ttree*> q;

    q.push(tree);

    while (! q.empty())
    {
        x = q.front();
        q.pop();

        search(x->inf, tree);

        if (x->left != NULL)
        {
            q.push(x->left);
        }
        if (x->right != NULL)
        {
            q.push(x->right);
        }
    }

    return 0;
}
