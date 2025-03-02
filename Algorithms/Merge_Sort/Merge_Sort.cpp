#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int s1 = mid - left + 1;
    int s2 = right - mid;

    vector<int> leftArray(s1);
    vector<int> rightArray(s2);

    for (int i = 0; i < s1; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < s2; i++)
        rightArray[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < s1 && j < s2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < s1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < s2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    ifstream infile("20000_Numbers.txt");
    if (!infile)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    vector<int> arr;
    int num, count = 0;
    //clock_t before = clock();
    while (infile >> num && count < 20000)
    {
        arr.push_back(num);
        count++;
    }
    //clock_t duration = clock() - before;
    //cout << "Duration: " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    infile.close();

    clock_t before = clock();
    mergeSort(arr, 0, arr.size() - 1);
    clock_t duration = clock() - before;
    cout << "Duration: " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << endl;


    return 0;
}
