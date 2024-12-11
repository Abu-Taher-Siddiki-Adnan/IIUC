#include <bits/stdc++.h>
using namespace std;

class Heap
{
    int heap[100000], SIZE = 0;

public:
    void Insert(int x)
    {
        heap[++SIZE] = x;
        int n = SIZE;
        while (n > 1)
        {
            if (heap[n / 2] < heap[n])
                swap(heap[n / 2], heap[n]);
            else
                break;
            n /= 2;
        }
    }

    int Delete()
    {
        if (SIZE == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int root = heap[1];
        heap[1] = heap[SIZE];
        SIZE--;

        int n = 1;
        while (2 * n <= SIZE)
        {
            int leftChild = 2 * n;
            int rightChild = 2 * n + 1;
            int largest = n;
            if (leftChild <= SIZE && heap[leftChild] > heap[largest])
                largest = leftChild;
            if (rightChild <= SIZE && heap[rightChild] > heap[largest])
                largest = rightChild;
            if (largest != n)
            {
                swap(heap[n], heap[largest]);
                n = largest;
            }
            else
                break;
        }
        return root;
    }

    bool isEmpty()
    {
        return SIZE == 0;
    }

    void display()
    {
        for (int i = 1; i <= SIZE; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

class PriorityQueue
{
    Heap h;

public:
    void enqueue(int x)
    {
        h.Insert(x);
    }

    int dequeue()
    {
        return h.Delete();
    }

    bool isEmpty()
    {
        return h.isEmpty();
    }

    void display()
    {
        h.display();
    }
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(44);
    pq.enqueue(30);
    pq.enqueue(50);
    pq.enqueue(22);
    pq.enqueue(60);
    pq.enqueue(55);
    pq.enqueue(77);
    pq.enqueue(55);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Dequeued: " << pq.dequeue() << endl;

    cout << "Priority Queue after dequeue: ";
    pq.display();

    return 0;
}
