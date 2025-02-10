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
        ll n, l, r, k;
        cin >> n >> l >> r >> k;
        // cout << n << l << r << k << endl;
        vecIn(vec, n);
        sort(all(vec));
        // vecOut(vec, n);
        // vll bable;
        ll total = 0;
        ll cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (vec[i] >= l and vec[i] <= r)
            {
                cost += vec[i];

                if (cost <= k)
                {
                    total++;
                    //cout << vec[i] << " ";
                }
                else
                    break;
            }
            // cout << cost << " ";
        }
        // cout << cost << " ";
        //cout << endl;
        print(total);
    }
    return 0;
}