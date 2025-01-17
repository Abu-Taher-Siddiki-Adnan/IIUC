#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> heap;
    int SIZE = 0;

public:
    Heap(int n)
    {
        heap.resize(n + 1, 0);
    }

    void InsertMax(int x)
    {
        heap[++SIZE] = x;
        int n = SIZE;
        while (n > 1 && heap[n / 2] < heap[n])
        {
            swap(heap[n / 2], heap[n]);
            n /= 2;
        }
    }

    void InsertMin(int x)
    {
        heap[++SIZE] = x;
        int n = SIZE;
        while (n > 1 && heap[n / 2] > heap[n])
        {
            swap(heap[n / 2], heap[n]);
            n /= 2;
        }
    }

    int DeleteMax()
    {
        if (SIZE == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int root = heap[1];
        heap[1] = heap[SIZE--];
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

    int DeleteMin()
    {
        if (SIZE == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int root = heap[1];
        heap[1] = heap[SIZE--];
        int n = 1;

        while (2 * n <= SIZE)
        {
            int leftChild = 2 * n;
            int rightChild = 2 * n + 1;
            int smallest = n;

            if (leftChild <= SIZE && heap[leftChild] < heap[smallest])
                smallest = leftChild;
            if (rightChild <= SIZE && heap[rightChild] < heap[smallest])
                smallest = rightChild;

            if (smallest != n)
            {
                swap(heap[n], heap[smallest]);
                n = smallest;
            }
            else
                break;
        }

        return root;
    }

    int getFront()
    {
        return SIZE > 0 ? heap[1] : -1;
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
    PriorityQueue(int n) : h(n) {}

    void enqueueMax(int x)
    {
        h.InsertMax(x);
    }

    void enqueueMin(int x)
    {
        h.InsertMin(x);
    }

    int dequeueMax()
    {
        return h.DeleteMax();
    }

    int dequeueMin()
    {
        return h.DeleteMin();
    }

    int getFront()
    {
        return h.getFront();
    }

    void display()
    {
        h.display();
    }

    bool isEmpty()
    {
        return h.isEmpty();
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Choose Priority Queue type:\n1. Max Heap\n2. Min Heap\n";
    int choice;
    cin >> choice;

    PriorityQueue pq(n);

    if (choice == 1)
    {
        cout << "Enter elements for Max Heap: \n";
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.enqueueMax(x);
        }
        cout << "Max Heap: ";
        pq.display();

        cout << "Dequeued element: " << pq.dequeueMax() << endl;
        cout << "Max Heap after dequeue: ";
        pq.display();
    }
    else if (choice == 2)
    {
        cout << "Enter elements for Min Heap: \n";
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.enqueueMin(x);
        }
        cout << "Min Heap: ";
        pq.display();

        cout << "Dequeued element: " << pq.dequeueMin() << endl;
        cout << "Min Heap after dequeue: ";
        pq.display();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
