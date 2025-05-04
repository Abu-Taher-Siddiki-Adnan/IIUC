#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, arr.size() - 1);

    clock_t duration = clock() - before;
    cout << "Duration: " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << endl;

    return 0;
}
