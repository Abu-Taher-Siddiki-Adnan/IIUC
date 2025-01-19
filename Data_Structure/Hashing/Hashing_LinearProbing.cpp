#include <bits/stdc++.h>
using namespace std;

vector<int> hTable;
int m;

int H(int key)
{
    return key % m;
}

void Insert(int key)
{
    int idx = H(key);
    while (hTable[idx] != -1)
    {
        idx = (idx + 1) % m;
    }
    hTable[idx] = key;
}

void Display()
{
    for (int i = 0; i < m; i++)
    {
        if (hTable[i] == -1)
        {
            cout << i << " : " << "empty" << endl;
        }
        else
        {
            cout << i << " : " << hTable[i] << endl;
        }
    }
}

int main()
{
    cin >> m;
    hTable.resize(m, -1);

    for (int i = 0; i < m; i++)
    {
        int key;
        cin >> key;
        Insert(key);
    }

    Display();
    return 0;
}
