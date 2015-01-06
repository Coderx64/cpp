struct tlist
{
	int inf; 
	tlist *next;
	tlist *prev;
};

void init_list(tlist *&h, tlist *&t)
{
	t = h = NULL;
}

void add_h(tlist *&h, tlist *&t, int i)
{
	tlist *r = new tlist;
	r -> inf = i;
	if(!h)
	{
		r -> next = NULL;
		t = r;
	}
	else
	{
		r -> next = h;
		h -> prev = r;
	}
	r -> prev = NULL;
	h = r;
}

void add_t(tlist *&h, tlist *&t, int i)
{
	tlist *r = new tlist;
	r -> inf = i;
	if(!h)
	{
		r -> prev = NULL;
		h = r;
	}
	else
	{
		t -> next = r;
		r -> prev = t;
	}
	r -> next = NULL;
	t = r;
}

void print_list(tlist *h, tlist *t)
{
	tlist *r = h;
	while(r)
	{
		printf("%d ", r -> inf);
		r = r -> next;
	}	
}

tlist * find(tlist *h, tlist *t, int i)
{
	tlist *p = h;
	while(p)
	{
		if(p -> inf == i)
			break;
		p = p -> next;
	}
	return p;
}

int remove(tlist *&h, tlist *&t, int i)
{
	tlist *r;
	r = find(h, t, i);
	if(r)
	{
		if(r == h && r == t)
			h = t = NULL;
		else 
			if(r == h)
			{
				h = h -> next;
				t -> next = NULL;
			}
			else 
				if(r == t)
				{
					t = t -> prev;
					t -> next = NULL;
				}
				else
				{
					(r -> prev) -> next = r -> next;
					(r -> next) -> prev = r -> prev;
				}
		delete r;
		return 1;
	}
	else
	return 0;
}

int find_max(tlist *h, tlist *t)
{
	int i, max = -99;
	tlist *p = h;
	while(p)
	{
		i = p -> inf;
		if(max < i)
			max = i;
		p = p -> next;
	}
	return max;
}