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

bool ckmin(int &a, int b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

bool ckmax(int &a, int b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vecIn(A, n, ll);
    map<ll, int> cnts;
    ll tot = 0;
    F0R(i, n + 1)
    {
        cnts[tot] = i;
        if (i < n)
            tot += A[i];
    }

    ll cur = 0;
    int ans = 0;
    for (int i = n; i >= 0; --i)
    {
        if (i < n)
            cur += A[i];
        if (cnts.count(cur) && cur * 2 <= tot)
            ckmax(ans, n - i + cnts[cur]);
    }

    print(ans);
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
