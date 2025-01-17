#include <bits/stdc++.h>
using namespace std;

int Size = 6;
int Priority = 10;
int arr[20][20] = {{0}};
int Front[20] = {0};
int Rear[20] = {0};

void Enqueue(int item, int prio)
{
    if (prio > Priority)
    {
        cout << "Invalid Priority" << endl;
        return;
    }
    if (Front[prio] == Rear[prio] + 1 or (Front[prio] == 1 and Rear[prio] == Size))
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (Front[prio] == 0)
        Front[prio]++;
    if (Rear[prio] == Size)
        Rear[prio] = 1;
    else
        Rear[prio]++;
    arr[prio][Rear[prio]] = item;
}

void Dequeue()
{
    for (int i = 1; i <= Priority; i++)
    {
        for (int j = 1; j <= Size; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = 0;
                Front[i]++;
                if (Front[i] > Size)
                    Front[i] = 1;
                return;
            }
        }
    }
    cout << "Queue is empty" << endl;
}
void Print()
{
    for (int i = 1; i <= Priority; i++)
    {
        bool hasData = false;
        for (int j = 1; j <= Size; j++)
        {
            if (arr[i][j] != 0)
            {
                cout << arr[i][j] << " ";
                hasData = true;
            }
        }
        if (hasData)
            cout << endl;
    }
}


int main()
{
    Enqueue(10, 1);
    Enqueue(20, 1);
    Enqueue(30, 1);
    Enqueue(40, 1);
    Enqueue(50, 1);
    Enqueue(60, 1);

    Print();

    Dequeue();
    Print();

    Enqueue(70, 1);
    Print();

    return 0;
}
