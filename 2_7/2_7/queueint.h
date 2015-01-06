#ifndef QUEUEINT_H_INCLUDED
#define QUEUEINT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#endif // QUEUEINT_H_INCLUDED

using namespace std;

struct tqueue
{
	int inf;
	tqueue *next;
};

void init_queue(tqueue *&h, tqueue *&t)
{
	h = t = NULL;
}
void insert(tqueue *&h, tqueue *&t, int item)
{
	tqueue *r = new tqueue;
	r -> inf = item;
	r -> next = NULL;
	if(!h && !t)
		h = t = r;
	else
	{
		t -> next = r;
		t = r;
	}
}

int take(tqueue *&h, tqueue *&t)
{
	tqueue *r = h;
	int i = r -> inf;
	h = r-> next;
	if(!h)
		t = NULL;
	delete r;
	return i;
}

void print_queue(tqueue *&h, tqueue *&t)
{
    tqueue *s, *r;
    int item;

    init_queue(s,r);

    while (h)
    {
        item = take(h,t);
        cout<<item<<" ";
        insert(s,r,item);
    }

    h = s;
    t = r;

    s = r = NULL;
}

int find_min(tqueue *&h, tqueue *&t)
{
    tqueue *s, *e;
    int item, n = INT_MAX;

    init_queue(s,e);

    while (h)
    {
        item = take(h,t);
        if (item < n)
        {
            n = item;
        }
        insert(s, e, item);
    }

    h = s;
    t = e;
    s = e = NULL;

    return n;
}

void remove_item(tqueue *&h, tqueue *&t, int item)
{
    tqueue *s, *e;
    int n;

    init_queue(s,e);

    while (h)
    {
        n = take(h,t);
        if (n != item)
        {
            insert(s, e, n);
        }
    }

    h = s;
    t = e;

    s = e = NULL;
}
