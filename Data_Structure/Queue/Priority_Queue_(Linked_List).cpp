//Implementation of a priority queue using linked-list.
#include <bits/stdc++.h>
using namespace std;

class Priority_Queue
{
    struct Node
    {
        int val;
        int priority;
        Node* next;
    };

    Node* Head;

    void add(int item,int p)
    {
        Node* nn = new Node;
        nn->val = item;
        nn->priority = p;
        nn->next = nullptr;

        if (Head == nullptr || p < Head->priority)
        {
            nn->next = Head;
            Head = nn;
        }
        else
        {
            Node* temp = Head;
            while (temp->next != nullptr && temp->next->priority <= p)
            {
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;
        }
    }
    void Delete()
    {
        if (Head == nullptr)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }
    void Print()
    {
        if (Head == nullptr)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = Head;
        while (temp)
        {
            cout << "(Value: " << temp->val << ", Priority: " << temp->priority << ")";
            if (temp->next != nullptr && temp->priority == temp->next->priority)
                cout << ", ";
            else
                cout << endl;
            temp = temp->next;
        }
    }
public:
    Priority_Queue()
    {
        Head = nullptr;
    }

    void Enqueue(int item, int p)
    {
        add(item,p);
    }
    void Deque()
    {
        Delete();
    }
    void Peek()
    {
        if (Head == nullptr)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Top element of the queue is: (Value: " << Head->val << ", Priority: " << Head->priority << ")" << endl;
    }
    bool IsEmpty()
    {
        return Head == nullptr;
    }

    void Display()
    {
        Print();
    }
};

int main()
{
    Priority_Queue pq;
    pq.Enqueue(10, 1);
    pq.Enqueue(20, 2);
    pq.Enqueue(11, 1);
    pq.Enqueue(30, 3);
    pq.Enqueue(60, 6);
    pq.Enqueue(22, 2);
    pq.Enqueue(40, 4);
    pq.Enqueue(31, 3);
    pq.Enqueue(50, 5);
    pq.Display();
    pq.Deque();
    pq.Peek();
    pq.Display();
    return 0;
}
