#include <iostream>
using namespace std;

class Queue
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
    void addLast(int item)
    {
        Node* nn = new Node;
        nn->data = item;
        nn->next = 0;

        if (head == 0)
        {
            head = tail = nn;
        }
        else
        {
            tail->next = nn;
            tail = nn;
        }
    }

    bool deleteFirst()
    {
        if (head == 0) return false;

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == 0)
        {
            tail = 0;
        }
        return true;
    }

public:
    Queue()
    {
        head = 0;
        tail = 0;
    }

    void push(int item)
    {
        addLast(item);
    }

    void pop()
    {
        if (!deleteFirst())
        {
            cout << "Queue Underflow" << endl;
        }
    }

    int top()
    {
        if (head == 0)
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return head->data;
    }

    bool empty()
    {
        return head == 0;
    }
};

int main()
{
    Queue s, t;

    s.push(5);
    s.push(15);
    s.push(25);

    t.push(10);
    t.push(100);
    t.push(1000);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    while (!t.empty())
    {
        cout << t.top() << " ";
        t.pop();
    }
    cout << endl;

    return 0;
}
