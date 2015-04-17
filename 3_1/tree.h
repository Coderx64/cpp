#include <iostream>
#include <cstdio>
using namespace std;

struct ttree
{
	int info;
	ttree *left, *right;
};
//FILE *f = fopen("input.txt", "r");

//добавление
int  tree_insert(ttree** tree, int info){
        ttree* p = *tree;
        while(p != NULL){
                if(info < p->info) {
                        tree = &p->left;
                        p    = p->left;
                } else {
                        if(info == p->info)
                                return 0;
                        tree = &p->right;
                        p    = p->right;
                }
        }
        if((p = new ttree()) != NULL){
                p->info   = info;
                p->left   = p->right = NULL;
                *tree     = p;
        }
        return (p != NULL);
}
