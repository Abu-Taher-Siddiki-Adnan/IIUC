#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<vector<int>> adj, vector<int> level)
{
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (level[v] == -1)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    cout << "Shortest distance of each node from source " << s << " : \n";
    for (int i=1;i<level.size();i++)
        cout << level[i] << " ";
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> level(n + 1, -1);

    int s;
    cin >> s;
    bfs(s, adj, level);
}