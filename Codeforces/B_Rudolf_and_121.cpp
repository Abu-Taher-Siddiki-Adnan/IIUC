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
        int n;
        cin >> n;
        vecIn(vec, n);
        bool possible = true;
        for (int i = 1; i < n - 1; i++)
        {
            int d = vec[i] / 2;
            if (d == vec[i - 1] and d <= vec[i + 1])
            {
                vec[i - 1] = 0;
                vec[i] %= 2;
                vec[i + 1] -= d;
            }
            else if (d > vec[i - 1])
            {
                int x = vec[i - 1];
                vec[i - 1] = 0;
                vec[i] -= 2 * x;
                vec[i + 1] -= x;
            }
        }
        int cnt = count(all(vec), 0);
        if (cnt == n)
            Yes;
        else
            No;
    }
    return 0;
}