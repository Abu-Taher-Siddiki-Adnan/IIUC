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
    ll x;
    cin >> x;
    bool possible = false;
    for (ll i = 1; i <= cbrt(x); i++)
    {
        ll a = i * i * i;
        ll b = x - a;
        double crt = cbrt(b);
        ll c = crt;
        //cout << a << " " << b << " " << c << endl;
        if (crt - c == 0 and b!=0)
        {
            possible = true;
            break;
        }
    }
    if (possible)
        Yes;
    else
        No;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}