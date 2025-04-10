#include <bits/stdc++.h>
using namespace std;

void bfs(int n, int s, int v, vector<vector<int>> adj)
{
    vector<int> level(n + 1, -1);
    vector<int> par(n + 1);
    level[s] = 0;
    par[s] = -1;
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
                par[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    path.push_back(v);
    int node = v;
    while (par[v] != -1)
    {
        path.push_back(par[v]);
        v = par[v];
    }

    reverse(path.begin(), path.end());
    cout << "Shortest path from source " << s << " to node " << node << " :\n";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i < path.size()-1)
            cout << " -> ";
    }
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

    int s;
    cin >> s;
    int v;
    cin >> v;
    bfs(n, s, v, adj);

    return 0;
}