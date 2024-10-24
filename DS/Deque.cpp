#include <iostream>
using namespace std;
class Deque
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
    void addFirst(int item)
    {
        Node* nn = new Node;
        nn->data = item;
        nn->next = head;
        if (head == 0)
        {
            tail = nn;
        }
        head = nn;
    }
    void addLast(int item)
    {
        Node* nn = new Node;
        nn->data = item;
        nn->next = 0;
        if (head == 0)
            head = tail = nn;
        else
        {
            tail->next = nn;
            tail = nn;
        }
    }
    bool deleteFirst()
    {
        if (head == 0)
            return false;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == 0)
            tail = 0;
        return true;
    }
    bool deleteLast()
    {
        if (head == 0)
            return false;
        if (head == tail)
        {
            delete head;
            head = tail = 0;
            return true;
        }
        Node* current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = 0;
        return true;
    }
public:
    Deque()
    {
        head = 0;
        tail = 0;
    }
    void InsertFront(int item)
    {
        addFirst(item);
    }
    void InsertRear(int item)
    {
        addLast(item);
    }
    void DeleteFront()
    {
        if (!deleteFirst())
            cout << "Deque Underflow" << endl;
    }
    void DeleteRear()
    {
        if (!deleteLast())
            cout << "Deque Underflow" << endl;
    }

    int GetFront()
    {
        if (head == 0)
        {
            cout << "Deque is empty!" << endl;
            return 0;
        }
        return head->data;
    }
    int GetRear()
    {
        if (tail == 0)
        {
            cout << "Deque is empty!" << endl;
            return 0;
        }
        return tail->data;
    }
    bool IsEmpty()
    {
        return head == 0;
    }
    bool IsFull()
    {
        Node* temp = new (nothrow) Node;
        if (temp == 0) return true;
        delete temp;
        return false;
    }
};

int main()
{
    Deque s, t;

    s.InsertRear(5);
    s.InsertRear(15);
    s.InsertRear(25);
    s.InsertFront(3);
    s.InsertFront(2);
    s.InsertFront(1);

    t.InsertRear(10);
    t.InsertRear(100);
    t.InsertRear(1000);
    t.InsertFront(7);
    t.InsertFront(6);
    t.InsertFront(5);

    cout << "Deque s: ";
    while (!s.IsEmpty())
    {
        cout << s.GetFront() << " ";
        s.DeleteFront();
    }
    cout << endl;

    cout << "Deque t: ";
    while (!t.IsEmpty())
    {
        cout << t.GetFront() << " ";
        t.DeleteFront();
    }
    cout << endl;

    return 0;
}
