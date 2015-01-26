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
        print_Tree(p->right,level + 1);
        for(int i = 0;i< level;i++) cout<<"   ";
        cout << p->info << endl;
        print_Tree(p->left,level + 1);
    }
}

ttree* findnd(ttree* src, int key)
{
    queue<ttree*> q;
    ttree* tmp;

    q.push(src);
    while (!q.empty()){
        tmp = q.front();
        q.pop();
        if (tmp->info == key){
            return tmp;
        }
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
    return NULL;
}

int compare(ttree* src, ttree* loss)
{
    ttree* findnode;
    ttree* tmpf;
    ttree* tmpl;
    queue<ttree*> srcnodes;
    queue<ttree*> lossnodes;

    findnode = findnd(src, loss->info);

    if (!findnode)
        return -1;
    srcnodes.push(findnode);
    lossnodes.push(loss);
    while (!lossnodes.empty())
    {
        tmpl = lossnodes.front();
        tmpf = srcnodes.front();
        if (tmpl->info != tmpf->info)
            return -1;
        cout<<tmpl->info<<" = "<<tmpf->info<<endl;
        lossnodes.pop();
        srcnodes.pop();
        if (tmpl->left)
            lossnodes.push(tmpl->left);
        if (tmpl->right)
            lossnodes.push(tmpl->right);
        if (tmpf->left)
            srcnodes.push(tmpf->left);
        if (tmpf->right)
            srcnodes.push(tmpf->right);
    }
    return 1;
}

int main()
{
    ttree* source = NULL;
    ttree* loss = NULL;

    FILE *f = fopen("input.txt", "r");
    int a;

    while (!feof(f)){
        fscanf(f, "%d", &a);
        tree_insert(&source, a);
    }
    fclose(f);

    f = fopen("search.txt", "r");
    while (!feof(f)){
        fscanf(f,"%d", &a);
        tree_insert(&loss, a);
    }

    printf("Source tree:\n");
    print_Tree(source,0);
    printf("Loss tree:\n");
    print_Tree(loss,0);
    printf("Result:\n");

    //printf("%d", findkey(source, 5, stat));
    if (compare(source, loss) == 1)
        printf("loss found in source!");
    else
        printf("not found(");

    return 0;
}
