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
    ll n, c;
    cin >> n >> c;
    vecIn(s,n,ll);

    ll l = 0, r = 1e9 / 2;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        ll sum = 0;
        bool ok = true;

        F0R(i,n)
        {
            ll val = s[i] + 2 * mid;
            if (val > sqrtl(c))
            {
                ok = false;
                break;
            }
            ll sq = val * val;
            if (sum > c - sq)
            {
                ok = false;
                break;
            }
            sum += sq;
        }

        if (ok)
            l = mid;
        else
            r = mid - 1;
    }

    print(l);
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
