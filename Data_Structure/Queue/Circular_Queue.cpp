#include <bits/stdc++.h>
using namespace std;

class Circular_Queue
{
    int Front, Rear, MaxSize;
    vector<int> Q;

public:
    Circular_Queue(int n)
    {
        Front = 0;
        Rear = 0;
        MaxSize = n;
        Q.resize(MaxSize + 1);
    }
    void Enqueue(int item)
    {
        if ((Rear + 1 == Front) || (Front == 1 && Rear == MaxSize))
        {
            cout << "Queue OVERLOADED!" << endl;
            return;
        }
        if (Front == 0)
            Front = 1;
        if (Rear == MaxSize)
            Rear = 1;
        else
            Rear++;
        Q[Rear] = item;
    }
    void Deque()
    {
        if (Front == 0 && Rear == 0)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        if (Front == Rear)
        {
            Front = Rear = 0;
        }
        else
        {
            Front = (Front + 1) % MaxSize;
        }
    }
    void Top()
    {
        if (Front == 0)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Top element of the Queue is : " << Q[Front] << endl;
    }
    void Display()
    {
        if (Front == 0)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Elements in the circular queue are: ";
        if (Front <= Rear)
        {
            for (int i = Front; i <= Rear; i++)
                cout << Q[i] << " ";
            cout << endl;
        }
        else
        {
            for (int i = 1; i <= Rear; i++)
                cout << Q[i] << " ";
            for (int i = Front; i <= MaxSize; i++)
                cout << Q[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Circular_Queue cq(5);
    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Enqueue(50);
    cq.Enqueue(60);
    cq.Top();
    cq.Display();
    cq.Deque();
    cq.Enqueue(70);
    cq.Top();
    cq.Display();

    return 0;
}
