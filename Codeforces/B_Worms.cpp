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
    cin >> n;
    vecIn(worms, n, int);
    vi prefixSum(n , 0);
    prefixSum[0] = worms[0];
    FOR(i, 1, n)
        prefixSum[i] = prefixSum[i - 1] + worms[i];
    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;
        auto it = lower_bound(all(prefixSum), x);
        int index = it - prefixSum.begin();
        print(index + 1); 
    }
    
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