#include <iostream>
#include <fstream>
#include <listint.h>
#include <queueint.h>
#include <stackint.h>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;

    if (in.is_open()) cout<<"File is successfully opened!"<<endl; else return -1;


    cout<<"Stack:"<<endl;
    tstack *head = init_stack();

    while (!in.eof())
    {
        in>>n;
        push(head, n);
    }

    print_stack(head);
    cout<<endl;
    remove_item(head, find_min(head));
    print_stack(head);

    /*---------Очередь----------*/
    cout<<endl<<"Queue:"<<endl;
    in.close();
    in.open("input.txt");

    tqueue *h,*t;

    init_queue(h,t);

    while (!in.eof())
    {
        in>>n;
        insert(h, t ,n);

    }

    print_queue(h,t);
    cout<<endl;
    remove_item(h,t,find_min(h,t));
    print_queue(h,t);

    /*---------------------------*/

    /*--------------------List-------*/
    cout<<endl<<"List:"<<endl;
    in.close();
    in.open("input.txt");

    tlist *hd, *tl;

    init_list(hd,tl);

    while (!in.eof())
    {
        in>>n;
        add_list_tail(hd, tl, n);
    }

    print_list_lr(hd, tl);
    remove(hd, tl, find_min(hd, tl));
    cout<<endl;
    print_list_lr(hd, tl);


    /*------------------------------------*/

    return 0;
}
