#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

// Function to calculate the size of the list
int SIZE(List lst)
{
    int cnt = 0;
    Node *ptr = lst.head;
    while (ptr)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

// Function to add a node at the beginning of the list
List addFirst(List lst, int val)
{
    Node *nn = new Node;
    nn->data = val;
    nn->next = lst.head;
    lst.head = nn;
    if (lst.tail == nullptr)
        lst.tail = nn;
    return lst;
}

// Function to add a node at the end of the list
List addLast(List lst, int val)
{
    Node *nn = new Node;
    nn->data = val;
    nn->next = NULL;
    if (lst.head == NULL)
        lst.head = lst.tail = nn; 
    else
    {
        lst.tail->next = nn; 
        lst.tail = nn;      
    }
    return lst;
}

// Function to insert a node at a specific position
List Insert(List lst, int pos, int item)
{
    int s = SIZE(lst);
    if (pos == 1)
        lst = addFirst(lst, item); 
    else if (pos == s + 1)
        lst = addLast(lst, item); 
    else if (pos > s + 1)
        return lst; 
    else
    {
        Node *nn = new Node;
        nn->data = item;
        Node *prev = lst.head;
        for (int i = 1; i <= pos - 2; i++)
            prev = prev->next;
        nn->next = prev->next;
        prev->next = nn;
    }
    return lst;
}

// Function to delete the head of the list
List headDlt(List lst)
{
    if (lst.head == NULL)
        return lst;
    Node *temp = lst.head;
    lst.head = lst.head->next;
    if (lst.head == NULL)
        lst.tail = NULL; // If the list is now empty, set tail to null
    delete temp;
    return lst;
}

// Function to delete a node at a specific position
List Delete(List lst, int pos)
{
    if (pos == 1)
        lst = headDlt(lst);
    else
    {
        Node *prev = lst.head;
        for (int i = 1; i <= pos - 2; i++)
        {
            prev = prev->next;
        }
        Node *cur = prev->next;
        prev->next = cur->next;
        if (cur == lst.tail)
            lst.tail = prev; 
        delete cur;
    }
    return lst;
}

// Function to search for an item in the list
void Search(List lst, int item)
{
    Node *ptr = lst.head;
    while (ptr)
    {
        if (ptr->data == item)
        {
            cout << "Found" << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Not Found" << endl;
}

// Function to merge two linked lists
List Merge(List lst1, List lst2)
{
    if (lst1.head == NULL)
        return lst2; 
    lst1.tail->next = lst2.head; 
    lst1.tail = lst2.tail;       
    return lst1;
}

// Function to copy a list
List Copy(List lst)
{
    List newList;
    if (lst.head == NULL)
        return newList;
    Node *ptr = lst.head;
    while (ptr)
    {
        newList = addLast(newList, ptr->data);
        ptr = ptr->next;
    }
    return newList;
}

// Function to reverse a list
List Reverse(List lst)
{
    List reversedList;
    Node *ptr = lst.head;
    while (ptr != nullptr)
    {
        reversedList = addFirst(reversedList, ptr->data);
        ptr = ptr->next;
    }
    return reversedList;
}

// Function to sort the list using bubble sort
List Sort(List lst)
{
    if (lst.head == nullptr)
    {
        return lst;
    }
    for (Node *i = lst.head; i != nullptr; i = i->next)
    {
        for (Node *j = lst.head; j->next != nullptr; j = j->next)
        {
            if (j->data > j->next->data)
                swap(j->data, j->next->data);
        }
    }
    return lst;
}

// Function to print the list
void Print(List lst)
{
    Node *ptr = lst.head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    List lst;
    lst = addFirst(lst, 5);
    lst = addLast(lst, 10);
    lst = Insert(lst, 2, 7);
    Print(lst);

    lst = Delete(lst, 2);
    Print(lst);

    Search(lst, 10);

    return 0;
}