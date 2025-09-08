/***********************************************************
 *                  Abu Taher Siddiki Adnan                *
 ***********************************************************/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vPi vector<pair<int, int>>
#define vPll vector<pair<ll, ll>>
#define Map map<int, int>
#define uMap unordered_map<int, int>
#define Set set<int>
#define uSet unordered_set<int>

#define all(a) a.begin(), a.end()
#define rev(n) n.rbegin(), n.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl
#define print(n) cout << n << endl
#define Pi M_PI
#define ff first
#define ss second
#define newline cout << endl

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define vecIn(v, n, type)       \
    vector<type> v(n);          \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

#define vecOut(v)         \
    for (auto &x : v)     \
        cout << x << " "; \
    cout << endl;

void solve()
{
    int n;
    cin >> n;
    string row1, row2;
    cin >> row1 >> row2;

    vector<string> grid = {row1, row2};
    vector<vector<bool>> vis(2, vector<bool>(n, false));

    queue<pi> q;
    q.push({0, 0});
    vis[0][0] = true;

    int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

    bool possible = false;

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second;

        if (r == 1 && c == n - 1)
        {
            possible = true;
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < 2 && nc >= 0 && nc < n)
            {
                if (!vis[nr][nc] && grid[nr][nc] == '0')
                {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    if (possible)
        Yes;
    else
        No;
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}