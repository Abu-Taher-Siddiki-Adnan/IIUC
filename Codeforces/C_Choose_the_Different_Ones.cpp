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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vecIn(a, n);
        vecIn(b, m);

        unordered_set<ll> setA(a.begin(), a.end());
        unordered_set<ll> setB(b.begin(), b.end());

        vector<bool> has(k + 1, false);
        int countA = 0, countB = 0;
        for (int i = 1; i <= k; ++i)
        {
            if (setA.count(i))
            {
                has[i] = true;
                countA++;
            }
            if (setB.count(i))
            {
                has[i] = true;
                countB++;
            }
        }
        bool ok = true;
        for (int i = 1; i <= k; i++)
        {
            if (!has[i])
            {
                ok = false;
                break;
            }
        }
        if (countA >= k / 2 and countB >= k / 2 and ok)
            Yes;
        else
            No;
    }

    return 0;
}
