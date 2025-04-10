#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
void dfs(int s)
{
    visited[s] = 1;
    cout << s << " ";
    for (int i = 0; i < adj[s].size(); i++)
    {
        int v = adj[s][i];
        if (!visited[v])
            dfs(v);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    adj = vector<vector<int>>(n + 1);
    visited = vector<int>(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin >> s;
    dfs(s);


    return 0;
}