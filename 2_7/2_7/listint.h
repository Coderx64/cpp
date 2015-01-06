#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#endif // LIST_H_INCLUDED

struct tlist
{
    int inf;
    tlist *next;
    tlist *prev;
};

tlist *head, *tail;

void init_list(tlist *&h, tlist *&t)
{
    h = t = NULL;
}

void add_list_head(tlist *&t, tlist *&h, int i)
{
    tlist *r = new tlist;
    r->inf = i;
    if (!h)
    {
        r->next = NULL;
        t = r;
    }
    else
    {
        r->next = h;
        h->prev = r;
    }
    r->prev = NULL;
    h = r;
}

void add_list_tail(tlist *&h, tlist *&t, int i)
{
    tlist *r = new tlist;
    r->inf = i;
    if (!h)
    {
        r->prev = NULL;
        h = r;
    }
    else
    {
        t->next = r;
        r->prev = t;
    }
    r->next = NULL;
    t = r;
}

void print_list_lr(tlist *&h, tlist *&t)
{
    tlist *r = h;
    while (r)
    {
        printf("%d ",r->inf);
        r = r->next;
    }
}

tlist * find(tlist *h,tlist *t, int i)
{
    tlist *p = h;
    while(p)
    {
        if (p->inf == i)
        {
            break;
        }
        p = p->next;
    }
    return p;
}

int find_min(tlist *&h, tlist *&t)
{
    int n = INT_MAX;
    tlist *r = h;

    while (r)
    {
        if (r->inf < n)
        {
            n = r->inf;
        }
        r = r->next;
    }

    return n;
}

int remove(tlist *&head, tlist *&tail, int i)
{
    tlist *r;
    r = find(head, tail, i);
    if (r)
    {
        if (r == head && r == tail)
        {
            head = tail = NULL;
        }
        else if (r == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if (r == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            (r->prev)->next = r->next;
            (r->next)->prev = r->prev;
        }
        delete r;
        return 1;
    }
    return 0;
}

int insert_yx(tlist *&head, tlist *&tail, int y, int x)
{
    tlist *r = find(head,tail,x);
    if (r)
    {
        tlist *p = new tlist;
        p->inf = y;
        p->next = r;
        p->prev = r->prev;
        if (r == head)
        {
            head = p;
        }
        else
        {
            r->prev->next = p;
        }
        r->prev = p;
        return 1;
    }
    return 0;
}

void list_del(tlist *&h, tlist *&t)
{
    tlist *r;
    while (h)
    {
        r = h;
        if (r == t)
        {
            h = t = NULL;
        }
        else
        {
            h = h->next;
            h->prev = NULL;
        }
        delete r;
    }
}
