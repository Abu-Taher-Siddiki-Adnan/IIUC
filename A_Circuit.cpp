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
        int n;
        cin >> n;
        vecIn(vec,2*n);
        int One = 0, Zero = 0;
        for (int i = 0; i < 2 * n; i++) 
        {
            if (vec[i] == 0)
                Zero++;
            else
                One++;
        }
        if (Zero == 0)
            cout << 0 << " " << 0 << endl;
        else
        {
            if (Zero >= One)
                cout << (Zero % 2) << " " << One << endl;
            else
                cout << (One % 2) << " " << Zero << endl;
        }
    }

    return 0;
}
