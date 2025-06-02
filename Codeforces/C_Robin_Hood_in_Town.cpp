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
    ll n;
    cin >> n;
    vecIn(a,n,int);

    if (n < 3)
    {
        print(-1);
        return;
    }

    ll mx = *max_element(all(a));
    ll sum = accumulate(all(a), 0ll);
    ll left = -1, right = 1e18;

    while (left + 1 < right)
    {
        ll mid = (left + right) / 2;
        ll avg = (sum + mid + 2 * n - 1) / (2 * n);
        bool flag = false;
        ll cnt = 0;

        F0R(i, n)
        {
            if (!flag && a[i] == mx)
            {
                flag = true;
                if (a[i] + mid < avg)
                    cnt++;
            }
            else if (a[i] < avg)
                cnt++;
        }

        if (cnt >= n / 2 + 1)
            right = mid;
        else
            left = mid;
    }

    print(right);
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