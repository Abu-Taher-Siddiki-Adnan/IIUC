#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vPi vector<pair<int, int>>
#define vPll vector<pair<ll, ll>>
#define uMap unordered_map<int, int>
#define rev(n) n.rbegin(), n.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl
#define print(n) cout << n << endl
#define Pi M_PI
#define newline cout << endl
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, n) FOR(i, 0, n)
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

const int MAXN = 2005;
int a[MAXN], mt[MAXN];
bool used[MAXN];
vector<int> g[MAXN];

bool dfs(int v)
{
    if (used[v])
        return false;
    used[v] = true;
    for (int u : g[v])
    {
        if (mt[u] == -1 || dfs(mt[u]))
        {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;

    FOR(i,1,n+1)
        cin >> a[i];
    FOR(i,1,n+1)
        g[i].clear();

    FOR(i,1,n+1)
    {
        int val = a[i];
        while (val)
        {
            if (val <= n)
                g[val].pb(i);
            val /= 2;
        }
    }

    FOR(i,1,n+1)
    {
        mt[i] = -1;
    }

    int res = 0;
    FOR(i,1,n+1)
    {
        fill(used + 1, used + n + 1, false);
        res += dfs(i);
    }

    if (res == n)
        Yes;
    else
        No;
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
