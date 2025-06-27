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

void solve()
{
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;
    vecIn(a, m, int);

    map<int, int> freq;
    F0R(i, m)
    freq[a[i]]++;

    vi res;
    int cnt = 0;

    auto get = [&](int x, int b)
    {
        int lo = 0, hi = n + 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (mid * (mid - 1) / 2 + b * mid <= x)
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    };

    for (auto it = freq.rbegin(); it != freq.rend(); it++)
    {
        int val = it->first, f = it->second;
        int take = get(f, cnt);
        F0R(i, take)
           res.pb(val);
        cnt += take;
    }

    vecOut(res);
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