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
int pw(int n)
{
    return (1 << n);
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
        int x, y;
        cin >> x >> y;
        if ((x + y) % 2 != 0)
            cout << -1 << " " << -1 << endl;
        else
        {
            if (x % 2 == 0 and y % 2 == 0)
                cout << x / 2 << " " << y / 2 << endl;
            else if ((x == 0 or x % 2 != 0) and y % 2 == 0)
                cout << x << " " << y / 2 << endl;
            else if ((y == 0 or y % 2 != 0) and x % 2 == 0)
                cout << x / 2 << " " << y << endl;
            else if (x % 2 != 0 and y % 2 != 0)
            {
                if (x >= y)
                {
                    x -= y;
                    x /= 2;
                }
                else
                {
                    y -= x;
                    y /= 2;
                }
                cout << x << " " << y << endl;
            }
            else
                cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}