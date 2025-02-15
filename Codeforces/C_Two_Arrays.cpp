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
        ll n;
        cin >> n;
        vecIn(a, n);
        vecIn(b, n);
        sort(all(a));
        sort(all(b));
        if (a == b)
            Yes;
        else
        {
            bool possible = true;
            for (int i = 0; i < n; i++)
            {
                //cout <<b[i]-a[i] << " ";
                if (b[i] - a[i] != 0 and b[i] - a[i] != 1)
                {
                    possible = false;
                    break;
                }
            }
            //newline;
            if (possible)
                Yes;
            else
                No;
        }
    }
    return 0;
}