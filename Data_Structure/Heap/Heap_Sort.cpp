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
    void Delete()
    {
        if (SIZE == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }
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
    }
    void top()
    {
        cout << heap[1] << " ";
    }
    void display()
    {
        for (int i = 1; i <= SIZE; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
    void heap_sort()
    {
        top();
        Delete();
        display();
    }
};

int main()
{
    Heap h;
    h.Insert(44);
    h.Insert(30);
    h.Insert(50);
    h.Insert(22);
    h.Insert(60);
    h.Insert(55);
    h.Insert(77);
    h.Insert(55);
    
    h.heap_sort();
}
