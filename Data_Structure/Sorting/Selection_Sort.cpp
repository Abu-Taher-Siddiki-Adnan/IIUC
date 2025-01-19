// selection sort
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0; i<n; i++)
    {
        cin>>v[i];
    }
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i +1;  j<n; j++)
        {
            if(v[j]< v[i])
            {
                swap(v[j],v[i]);
            }
        }
    }
    for(int i : v)
    {
        cout<< i << " ";
    }
}