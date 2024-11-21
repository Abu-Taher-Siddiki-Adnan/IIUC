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

    int q;
    cin >> q;
    while (q--)
    {
        string s, t;
        cin >> s >> t;
        int lenS = sz(s);
        int lenT = sz(t);
        int lcm = (lenS * lenT) / __gcd(lenS, lenT);
        string tempS = "";
        for (int i = 0; i < lcm / lenS; i++)
            tempS += s;
        string tempT = "";
        for (int i = 0; i < lcm / lenT; i++)
            tempT += t;
        // print(tempS);
        // print(tempT);
        if (tempS == tempT)
            print(tempS);
        else
            cout << -1 << endl;
    }

    return 0;
}
