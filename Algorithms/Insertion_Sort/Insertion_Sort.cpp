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
    clock_t before = clock();
    int num, count = 0;
    while (infile >> num && count < 20000)
    {
        arr.push_back(num);
        count++;
    }
    clock_t duration = clock() - before;

    cout << "Duration: " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    infile.close();

    int n = arr.size();

    //clock_t before = clock();
    sort(arr.data(), n);
    //clock_t duration = clock() - before;

    //cout << "Duration: " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << endl;

    return 0;
}
