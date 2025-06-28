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
#define ff first
#define ss second
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

void solve()
{
    int n;
    cin >> n;
    vi p(2 * n + 1); 
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        p[x] = i;
    }

    int res = 0; 
    for (int a = 1; a <= 2 * n; a++)
    {
        for (int b = 1; b < a && a * b <= 2 * n; b++)
        {
            if (p[a] && p[b] && a * b == p[a] + p[b])
                res++;
        }
    }

    print(res);
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