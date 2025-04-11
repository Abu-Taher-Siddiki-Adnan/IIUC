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
#define vecOut(v)                   \
    for (int i = 0; i < sz(v); i++) \
    {                               \
        cout << v[i] << " ";        \
    }                               \
    cout << endl;

void Solve()
{
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    while (k--)
    {
        int q;
        cin >> q;
        int l = 0, r = n - 1;
        bool found = false;
        int indx = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (vec[m] <= q)
            {
                found = true;
                indx = m;
                l = m + 1;
            }
            else if (vec[m] > q)
                r = m-1;
        }
        if (found)
            print(indx + 1);
        else
            print(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    Solve();
    // }

    return 0;
}