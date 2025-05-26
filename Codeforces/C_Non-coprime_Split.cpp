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
#define vPi vector<pi>
#define vPll vector<pll>
#define uMap unordered_map<int, int>
#define rev(n) n.rbegin(), n.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES\n"
#define No cout << "NO\n"
#define print(n) cout << n << endl
#define newline cout << endl
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, n) FOR(i, 0, n)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int l, r;
    cin >> l >> r;

    if (l != r || r % 2 == 0)
    {
        int x = r - r % 2;
        if (x == 2)
        {
            print(-1);
            return;
        }
        cout << x / 2 << ' ' << x / 2 << endl;
        return;
    }

    bool found = false;
    for (int d = 2; d * d <= l; ++d)
    {
        if (l % d)
            continue;
        ll k = l / d;
        if (k == 1)
            continue;
        cout << d << ' ' << (k - 1) * d << endl;
        found = true;
        break;
    }

    if (!found)
        print(-1);
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
