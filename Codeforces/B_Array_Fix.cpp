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
    vecIn(a, n, int);

    vector<vector<bool>> dp(n + 1, vector<bool>(105, false));
    F0R(c, 105)
       dp[0][c] = true;

    F0R(i, n)
    {
        string s = to_string(a[i]);
        int x = s.front() - '0';
        int y = s.back() - '0';

        F0R(j, 105)
        {
            dp[i + 1][j] = false;

            if (j >= a[i] && dp[i][a[i]])
                dp[i + 1][j] = true;

            if (j >= y && dp[i][x] && x <= y)
                dp[i + 1][j] = true;
        }
    }

    bool ans = false;
    F0R(j, 105)
       ans |= dp[n][j];

    if(ans)
        Yes;
    else
        No;
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
