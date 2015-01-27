#include <iostream>
#include <fstream>

using namespace std;

struct tlist{int inf; tlist * next;};
tlist * mas[10];
int n = 5;

tlist *in_stack()
{return NULL;}

void push (tlist*&s, int item){
	tlist *r = new tlist;
	r->inf = item; r-> next = s;
	s = r;
}

int pop (tlist *&s){
	tlist *r=s; int i=r->inf;
	s=r->next;
	delete r;
	return i;
}

int main()
{
	int k, a, j = 0, tmp = 1;
	fstream in("input1.txt", ios_base::in);
	for(int i = 0; i < n; i++)
	{
		mas[i] = in_stack();
		tmp = 1;
		while(tmp != 0)
		{
			in >> tmp;
			if(tmp == 0 && tmp > 1000 && tmp < -1000)
				break;
			else
			{
				push(mas[i], tmp);
				cout << tmp << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	cin >> a;

	for(int i = 0; i<n; i++)
	{
        while(&mas[i]->inf != NULL )
        {
            tmp = pop(mas[i]);
            if(tmp == a)
            {
                cout << tmp << " ";
            }
        }
        cout << endl;
	}
}
