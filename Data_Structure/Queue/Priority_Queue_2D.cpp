//Implementation of Priority Queue using 2D Array
#include <bits/stdc++.h>
using namespace std;

class Priority_Queue
{
    int maxSize, maxPriority;
    vector<vector<int>> Q;
    vector<int> Front;
    vector<int> Rear;

    void add(int item, int p)
    {
        if (p < 1 || p > maxPriority)
        {
            cout << "Invalid priority!" << endl;
            return;
        }

        if ((Front[p] == 1 && Rear[p] == maxSize) || Front[p] == Rear[p] + 1)
        {
            cout << "Queue OVERLOADED for priority " << p << "!" << endl;
            return;
        }

        if (Front[p] == 0)
        {
            Front[p] = 1;
            Rear[p] = 1;
        }
        else
        {
            if (Rear[p] == maxSize)
                Rear[p] = 1;
            else
                Rear[p]++;
        }

        Q[p][Rear[p]] = item;
    }
    void Delete()
    {
        for (int i = 1; i <= maxPriority; i++)
        {
            for (int j = 1; j <= maxSize; j++)
            {
                if (Q[i][j] != 0)
                {
                    Q[i][j] = 0;
                    Front[i]++;
                    if (Front[i] > maxSize)
                        Front[i] = 1;
                    return;
                }
            }
        }
        cout << "Queue is empty" << endl;
    }

    void Print()
    {
        for (int i = 1; i <= maxPriority; i++)
        {
            cout << "Priority " << i << ": ";
            bool hasData = false;
            for (int j = 1; j <= maxSize; j++)
            {
                if (Q[i][j] != 0)
                {
                    cout << Q[i][j] << " ";
                    hasData = true;
                }
            }
            if (!hasData)
                cout << "EMPTY";
            cout << endl;
        }
    }

public:
    Priority_Queue(int n, int p)
    {
        maxPriority = p;
        maxSize = n;

        Front.resize(maxPriority + 1, 0);
        Rear.resize(maxPriority + 1, 0);
        Q.resize(maxPriority + 1, vector<int>(maxSize + 1, 0));
    }

    void Enqueue(int item, int p)
    {
        add(item, p);
    }
    void Deque()
    {
        Delete();
    }
    void Display()
    {
        Print();
    }
};

int main()
{
    Priority_Queue pq(5, 5);

    pq.Enqueue(20, 2);
    pq.Enqueue(40, 4);
    pq.Enqueue(21, 2);
    pq.Enqueue(10, 1);
    pq.Enqueue(44, 4);
    pq.Enqueue(11, 1);
    pq.Enqueue(22, 2);
    pq.Enqueue(23, 2);
    pq.Enqueue(24, 2);
    pq.Enqueue(25, 2);
    pq.Enqueue(12, 1);
    pq.Display();
    
    pq.Deque();
    pq.Display();

    return 0;
}
