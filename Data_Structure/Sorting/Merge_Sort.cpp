//Merge Sort
#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10001);

void merge(int left, int mid, int right)
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

void mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
