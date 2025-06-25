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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
    {
        int side = abs(y2 - y1);
        cout << x1 + side << " " << y1 << " " << x2 + side << " " << y2 << endl;
    }
    else if (y1 == y2)
    {
        int side = abs(x2 - x1);
        cout << x1 << " " << y1 + side << " " << x2 << " " << y2 + side << endl;
    }
    else if (abs(x2 - x1) == abs(y2 - y1))
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    else
       print(-1);
}
int main()
{
    fast_io;

    int t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}