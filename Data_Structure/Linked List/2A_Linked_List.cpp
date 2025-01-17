#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

struct List
{
    Node* head = 0;
    Node* tail = 0;
};

List addFirst(List lst,int item)
{
    Node* nn = new Node;
    nn->data = item;
    nn->next = lst.head;
    nn->prev = 0;
    if(lst.head == 0)
    {
        lst.tail = nn;
    }
    if(lst.head != 0)
    {
        lst.head->prev = nn;
    }
    lst.head = nn;
    return lst;
}
List addLast(List lst,int item)
{
    if(lst.head == 0)
    {
        addFirst(lst,item);
        return lst;
    }

    Node* nn = new Node;
    nn->data = item;
    nn->next = 0;
    nn->prev = lst.tail;

    lst.tail->next = nn;
    lst.tail = nn;
    return lst;
}

List Insert(List lst,int pos, int item)
{
    int s = Size(lst);
    if(pos==1)
        addFirst(lst,item);
    else if(pos==s+1)
        addLast(lst,item);
    else
    {
        Node *nn = new Node;
        nn->data = item;
        Node *pre = lst.head;
        for(int i=1;i<pos-1;i++)
            pre = pre->next;
        Node* cur = pre->next;
        nn->next = cur;
        nn->prev = pre;
        pre->next = nn;
    }
    return lst;
}
int Size(List lst)
{
    int cnt = 0;
    Node* ptr = lst.head;
    while(ptr)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}
void Print(List lst,bool ltor)
{
    if(ltor)
    {
        cout << "Printing L to R: ";
        Node* ptr = lst.head;
        while(ptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "Printing R to L: ";
        Node* ptr = lst.tail;
        while(ptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
    }
    cout << endl;
}
int main()
{
    List list1;
    /// 12 11 10
    list1 = addLast(list1,10);
    list1 = addLast(list1,20);
    list1 = addLast(list1,30);

    Print(list1,1);
    Print(list1,0);
    return 0;
}
