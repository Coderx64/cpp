#ifndef STACKINT_H_INCLUDED
#define STACKINT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#endif // STACKINT_H_INCLUDED

using namespace std;

struct tstack
{
    int inf;
    tstack *next;
};

tstack * init_stack()
{
    return  NULL;
}

void push(tstack *&s, int item)
{
    tstack *r = new tstack;
    r->inf = item;
    r->next = s;
    s = r;
}

int pop(tstack *&s)
{
    tstack *r = s;
    int i = r->inf;
    s = r->next;
    delete r;
    return i;
}

int peek(tstack *s)
{
    return s->inf;
}

int empty_stack(tstack *s)
{
    return (s) ? 0: 1;
}

//Removes all occurrences item x from of a specified stack
void remove_item(tstack *&s, int x)
{
    tstack *r = init_stack();
    int i;

    while (!empty_stack(s))
    {
        i = pop(s);
        if (i != x)
        {
            push(r,i);
        }
    }

    s = r;
    r = NULL;
}

//Find the minimum element of the stack
int find_min(tstack *&s)
{
    tstack *r = init_stack();


    int item, min_item;

    min_item = INT_MAX;

    while (!empty_stack(s))
    {
        item = pop(s);
        if (item < min_item)
        {
            min_item = item;
        }
        push(r,item);
    }
    s = r;
    r = NULL;
    return min_item;
}

//Printing items of stack on screen
void print_stack(tstack *&s)
{
    int item;
    tstack *r = init_stack();

    while (!empty_stack(s))
    {
        item = pop(s);
        cout<<item<<" ";
        push(r, item);
    }

    s = r;
    r = NULL;
}
