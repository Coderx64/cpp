struct tstack
{
	int inf; 
	tstack *next;
};

tstack *init_stack()
{
	return NULL;
}

void push(tstack *&s, int item)
{
	tstack *r = new tstack;
	r -> inf = item;
	r -> next = s;
	s = r;
}

int pop(tstack *&s)
{
	tstack *r = s;
	int i = r -> inf;
	s = r -> next;
	delete r;
	return i;
}

int peek(tstack *s)
{
	return s-> inf;
}

int empty_stack(tstack *s)
{
	return(s) ? 0: 1;
}

