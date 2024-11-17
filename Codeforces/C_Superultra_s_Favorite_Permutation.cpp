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
        if (n <= 4)
        {
            cout << -1 << endl;
            continue;
        }
        vll oddVec;
        for (ll i = 1; i <= n; i += 2)
        {
            cout << i << " ";
            oddVec.pb(i);
        }
        vll vec;
        for (ll i = 2; i <= n; i += 2)
            vec.pb(i);
        reverse(all(vec));
        ll x = sz(oddVec) - 1;
        ll ignr;
        for (ll i = 0; i < sz(vec); i++)
        {
            if ((oddVec[x] + vec[i]) % 3 == 0)
            {
                cout << vec[i] << " ";
                ignr = vec[i];
                break;
            }
        }
        for (ll i = 0; i < sz(vec); i++)
        {
            if (vec[i] == ignr)
                continue;
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    return 0;
}