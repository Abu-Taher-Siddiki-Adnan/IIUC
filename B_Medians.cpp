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
#define Y cout << "YES" << endl
#define N cout << "NO" << endl
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
        if (k == 1 && n == 1) 
        {
            cout << 1 << endl;
            cout << 1 << endl;
        }
        else if (k == 1 || k == n && n != 1) 
        {
            cout << -1 << endl;
        }
        else if (k % 2 == 1) 
        {
            cout << 3 << endl;
            cout << 1 << " " << k - 1 << " "  << k + 2 << endl;
        }
        else
        {
            cout << 3 << endl;
            cout << 1 << " " << k << " "  << k + 1 << endl; 
        }
    }

    return 0;
}
