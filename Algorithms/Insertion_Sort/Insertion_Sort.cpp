#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    ifstream infile("20000Numbers.txt");
    if (!infile)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    vector<int> arr;
    int num;
    while (infile >> num)
    {
        arr.push_back(num);
    }
    infile.close();

    int n = arr.size();

    auto start = chrono::high_resolution_clock::now();
    sort(arr.data(), n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cout << "Time taken for sorting: " << duration.count() << " milliseconds" << endl;


    return 0;
}
