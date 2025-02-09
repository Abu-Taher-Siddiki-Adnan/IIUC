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
        int n, m;
        cin >> n >> m;
        vecIn(vec, n);
        ll b;
        cin >> b;
        ll prev = min(vec[0], b - vec[0]);
        bool possible = true;
        for (int i = 1; i < n; i++)
        {
            ll cur = vec[i];
            ll op1 = cur;
            ll op2 = b - cur;

            if (op1 < prev and op2 < prev)
            {
                possible = false;
                break;
            }
            prev = min(op1 >= prev ? op1 : LLONG_MAX, op2 >= prev ? op2 : LLONG_MAX);
        }
        if (possible)
            Yes;
        else
            No;
    }
    return 0;
}