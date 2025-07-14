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

int n, x;
vi h, p;
vvi dp;

int func(int i, int rem)
{
    if (i == n || rem <= 0)
        return 0;

    if (dp[i][rem] != -1)
        return dp[i][rem];

    int r1 = func(i + 1, rem);
    int r2 = 0;
    if (rem >= h[i])
        r2 = p[i] + func(i + 1, rem - h[i]);

    return dp[i][rem] = max(r1, r2);
}

void solve()
{
    cin >> n >> x;
    h.resize(n);
    p.resize(n);
    F0R(i, n)
        cin >> h[i];
    F0R(i, n)
        cin >> p[i];

    dp.assign(n + 1, vi(x + 1, -1));

    print(func(0, x));
}
int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
