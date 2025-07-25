/***********************************************************
 *                  Abu Taher Siddiki Adnan                *
 ***********************************************************/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vPi vector<pair<int, int>>
#define vPll vector<pair<ll, ll>>
#define Map map<int,int>
#define uMap unordered_map<int, int>
#define Set set<int>
#define uSet unordered_set<int>

#define all(a) a.begin(), a.end()
#define rev(n) n.rbegin(), n.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl
#define print(n) cout << n << endl
#define Pi M_PI
#define ff first
#define ss second
#define newline cout << endl

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)

#define fast_io \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define vecIn(v, n, type)       \
    vector<type> v(n);          \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

#define vecOut(v)         \
    for (auto &x : v)     \
        cout << x << " "; \
    cout << endl;


const int MOD = 1e9 + 7;
int countWays(int i, int x, vi &coins, vi &dp)
{
    if (i > x)
        return dp[x]; 
    for (int val : coins)
    {
        if (i - val >= 0)
        {
            dp[i] = (dp[i] + dp[i - val]) % MOD;
        }
    }
    return countWays(i + 1, x, coins, dp);
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vecIn(coins, n, int);
    vi dp(x + 1, 0);
    dp[0] = 1;
    print(countWays(1, x, coins, dp));
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