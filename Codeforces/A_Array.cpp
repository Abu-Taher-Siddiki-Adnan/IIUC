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
    int n, q, z = 1, hz = 0;
    cin >> n;

    vi v1, v2, v3;

    F0R(i, n)
    {
        cin >> q;
        if (q == 0)
            hz = 1;
        if (q == 0)
            v3.pb(q);
        else if (q < 0)
        {
            if (v1.empty())
                v1.pb(q);
            else
            {
                v2.pb(q);
                z = -z;
            }
        }
        else
            v2.pb(q);
    }

    sort(all(v2));
    if (z == -1 && v2[0] < 0)
    {
        v3.pb(v2[0]);
        v2.erase(v2.begin());
        z = 1;
    }

    if (hz == 0 || z == -1 || v1.empty() || v2.empty() || v3.empty())
    {
        print(-1);
        return;
    }

    cout << sz(v1) << " ";
    vecOut(v1);
    cout << sz(v2) << " ";
    vecOut(v2);
    cout << sz(v3) << " ";
    vecOut(v3);
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
