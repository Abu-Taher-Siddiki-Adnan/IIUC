#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(maxElement + 1, 0);

    for (int x : arr)
        count[x]++;
    int index = 0;

    for (int i = 0; i <= maxElement; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
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
    while (infile >> num && count < 10000)
    {
        arr.push_back(num);
        count++;
    }
    
    infile.close();
    
    clock_t before = clock();

    countingSort(arr);

    clock_t duration = clock() - before;
    cout << "Duration: " << (float)duration * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
