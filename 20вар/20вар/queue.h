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
	r -> inf = item; r -> next = NULL;
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