#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    ifstream infile("Random_Numbers.txt");
    if (!infile)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    vector<int> arr;
    int num, count = 0;
    while (infile >> num && count < 100000)
    {
        arr.push_back(num);
        count++;
    }

    infile.close();

    clock_t before = clock();

    heapSort(arr);

    clock_t duration = clock() - before;
    cout << "Duration: " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << endl;

    return 0;
}
