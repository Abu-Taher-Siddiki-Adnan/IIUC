#include <bits/stdc++.h>
using namespace std;

int cqueue[10];
int front = 0, rear = 0, Size = 6;

void Enqueue(int item)
{
    if ((rear + 1 == front) || (front == 1 && rear == Size))
    {
        cout << "Queue is full\n";
        return;
    }
    if (front == 0)
        front = 1;
    if (rear == Size)
        rear = 1;
    else
        rear++;
    cqueue[rear] = item;
}

void Dequeue()
{
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty\n";
        return;
    }
    else if (front == rear)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (front == Size)
            front = 1;
        else
            front++;
    }
}
int Top()
{
    if(front==0)
    {
        cout << "Queue is Empty!" << endl;
        return 0;
    }
    return cqueue[front];
}
void Print()
{
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    if (front > rear)
    {
        for (int i = 1; i <= rear; i++)
            cout << cqueue[i] << " ";
        for (int i = front; i <= Size; i++)
            cout << cqueue[i] << " ";
    }
    else if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            cout << cqueue[i] << " ";
    }
    cout << endl;
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);
    Print();
    //cout << "Top Element of the Queue is : " << Top() << endl;
    // Dequeue();
    // Print();
    // Enqueue(10);
    // Print();
    return 0;
}
