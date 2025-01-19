//Quick Sort
#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10001);

int partition(int start, int end)
{
    int pi = start - 1;
    int p = arr[end];

    for (int cur = start; cur < end; cur++)
    {
        if (arr[cur] <= p)
        {
            pi++;
            swap(arr[cur], arr[pi]);
        }
    }
    pi++;
    swap(arr[pi], arr[end]);
    return pi;
}

void quickSort(int start, int end)
{
    if (start < end)
    {
        int pi = partition(start, end);
        quickSort(start, pi - 1);
        quickSort(pi + 1, end);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
