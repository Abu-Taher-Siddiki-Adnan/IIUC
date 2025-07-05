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
    int n, m;
    cin >> n >> m;
    vvi a(n + 1, vi(m + 1));
    int mx = 0;

    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m + 1)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    vi row(n + 1), col(m + 1);
    int cnt = 0;

    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m + 1)
        {
            if (a[i][j] == mx)
                row[i]++, col[j]++, cnt++;
        }
    }
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m + 1)
        {
            if (row[i] + col[j] - (a[i][j] == mx) == cnt)
            {
                print(mx - 1);
                return;
            }
        }
    }

    print(mx);
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