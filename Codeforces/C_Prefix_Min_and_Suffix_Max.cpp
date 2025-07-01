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
    vecIn(v, n, int);

    if (n == 1)
    {
        print(1);
        return;
    }

    vi pre(n), suf(n);
    pre[0] = v[0];
    FOR(i, 1, n)
        pre[i] = min(pre[i - 1], v[i]);
    //vecOut(pre);
    suf[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], v[i]);
    //vecOut(suf);

    string ans = "";
    F0R(i, n)
    {
        int l, r;
        if (i == 0)
            l = INT_MAX;
        else
            l = pre[i - 1];

        if (i == n - 1)
            r = INT_MIN;
        else
            r = suf[i + 1];

        if (v[i] < l || v[i] > r)
            ans += '1';
        else
            ans += '0';
    }
    print(ans);
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