#include <bits/stdc++.h>
using namespace std;
int main()
{
    int vrtx,egs;
    cin>>vrtx>>egs;
    vector<int> adj_List[vrtx];
    while(egs--)
    {
        int a,b; cin>>a>>b;
        adj_List[a].push_back(b);
        adj_List[b].push_back(a);
    }
    for(int i = 0; i<vrtx; i++)
    {
        for(int  x : adj_List[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
