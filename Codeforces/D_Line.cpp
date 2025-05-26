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
    string s;
    cin >> s;

    vll gains;
    ll base = 0;
    F0R(i, n)
    {
        if (s[i] == 'L')
        {
            base += i;
            ll gain = (n - i - 1LL) - i;
            if (gain > 0)
                gains.push_back(gain);
        }
        else
        {
            base += (n - i - 1LL);
            ll gain = i - (n - i - 1LL);
            if (gain > 0)
                gains.push_back(gain);
        }
    }

    sort(gains.rbegin(), gains.rend());

    vll result(n);
    ll total = base;
    F0R(k, n)
    {
        if (k < sz(gains))
            total += gains[k];
        result[k] = total;
    }

    vecOut(result);
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
