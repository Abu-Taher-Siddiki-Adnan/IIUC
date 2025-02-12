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
        ll n, m;
        cin >> n >> m;
        vecIn(a,n);
        vecIn(b,m);
        ll mp = min_element(all(b)) - b.begin();
        vll best = a;
        for (int i = 0; i <= n - m; i++)
        {
            bool change = false;
            for (int j = 0; j < m; j++)
            {
                if (best[i + j] < b[(j + mp) % m])
                    break;
                if (best[i + j] > b[(j + mp) % m])
                {
                    change = true;
                    break;
                }
            }
            if (change)
            {
                for (int j = 0; j < m; j++)
                    best[i + j] = b[(j + mp) % m];
            }
        }
        vecOut(best, n);
    }
    return 0;
}
