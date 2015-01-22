#include <iostream>
#include <cstdlib>
#include "tree.h"
#include <queue>
#include <fstream>
//#include <iostream>

using namespace std;

void print_Tree(ttree* p,int level)
{
    if(p)
    {
        print_Tree(p->left,level + 1);
        for(int i = 0;i< level;i++) cout<<"   ";
        cout << p->info << endl;
        print_Tree(p->right,level + 1);
    }
}

int main()
{
    ttree* tree = NULL;
    FILE *f = fopen("input.txt", "r");
    int a;

    while (!feof(f)){
        fscanf(f, "%d", &a);
        tree_insert(&tree, a);
    }

    print_Tree(tree,0);
    return 0;
}


