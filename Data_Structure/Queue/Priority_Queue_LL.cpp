#include <iostream>
using namespace std;

class PriorityQueue
{
    struct Node
    {
        int data;
        int priority;
        Node *next;
    };
    Node *head;
    void Insert(int item, int prio)
    {
        Node *nn = new Node;
        nn->data = item;
        nn->priority = prio;
        nn->next = 0;
        if (head == 0 || prio < head->priority)
        {
            nn->next = head;
            head = nn;
        }
        else
        {
            Node *temp = head;
            while (temp->next != 0 && temp->next->priority <= prio)
            {
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;
        }
    }
    bool deleteFirst()
    {
        if (head == 0)
            return false;
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

public:
    PriorityQueue()
    {
        head = 0;
    }

    void Enqueue(int item, int priority)
    {
        Insert(item, priority);
    }
    void Dequeue()
    {
        if (!deleteFirst())
        {
            cout << "Queue Underflow" << endl;
        }
    }

    int Peek()
    {
        if (head == 0)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    bool IsEmpty()
    {
        return head == 0;
    }

    void display()
    {
        if (head == 0)
        {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != 0)
        {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;
    //if (pq.IsEmpty())
        //cout << "Priority Queue is empty!" << endl;
    // pq.display();
    pq.Enqueue(5, 2);
    pq.Enqueue(15, 1);
    pq.Enqueue(25, 3);
    pq.Enqueue(10, 0);
    pq.Enqueue(20, 1);
    pq.display();

    cout << "Top element: " << pq.Peek() << endl;

    pq.Dequeue();
    pq.Dequeue();
    pq.display();

    return 0;
}
