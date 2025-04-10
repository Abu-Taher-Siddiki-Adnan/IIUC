//Find Shortest distance of a destination from source in a grid
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second

int n, m;
vector<string> grid;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y)
{
    return x < n and x >= 0 and y < m and y >= 0 and grid[x][y] != '#';
}

void bfs(pii s, pii d)
{
    int level[100][100];
    memset(level, -1, sizeof(level));
    level[s.ff][s.ss] = 0;

    queue<pii> q;
    q.push(s);
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pii v = {u.ff + dx[i], u.ss + dy[i]};
            if (isValid(v.ff, v.ss) and level[v.ff][v.ss] == -1)
            {
                level[v.ff][v.ss] = level[u.ff][u.ss] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << level[i][j] << " ";
        cout << endl;
    }

    cout << "Shortest distance of the destination from the source is : " << level[d.ff][d.ss] << endl;
}

int main()
{
    cin >> n >> m;
    grid = vector<string>(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    pii s, d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'S')
            {
                s.ff = i;
                s.ss = j;
            }
            if (grid[i][j] == 'D')
            {
                d.ff = i;
                d.ss = j;
            }
        }
    }
    bfs(s, d);
}