#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define rev(n) n.rbegin(), n.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl
#define print(n) cout << n << endl
#define Pi M_PI
#define newline cout << endl
#define vecIn(v, n)             \
    vll v;                      \
    for (int i = 0; i < n; i++) \
    {                           \
        ll x;                   \
        cin >> x;               \
        v.pb(x);                \
    };
#define vecOut(v, n)            \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << v[i] << " ";    \
    }                           \
    cout << endl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vecIn(vec, n);
        ll ans = LLONG_MAX;
        int evenCnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (vec[i] % 2 == 0)
                evenCnt++;
            if (vec[i] % k == 0)
                ans = 0;
            ans = min(k - vec[i] % k, ans);
        }
        if (k == 4)
        {
            if (evenCnt >= 2)
                ans = 0;
            else if (evenCnt == 1)
                ans = min(ans, 1LL);
            else
                ans = min(ans, 2LL);
        }
        print(ans);
    }
    return 0;
}
