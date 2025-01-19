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

    void display()
    {
        for (int i = 1; i <= SIZE; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    Heap h;
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        h.Insert(x);
    }

    h.display();

    return 0;
}

