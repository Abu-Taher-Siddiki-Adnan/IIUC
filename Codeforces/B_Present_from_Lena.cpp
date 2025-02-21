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
    for (int i = 0; i < n; i++) \
    {                           \
        ll x;                   \
        cin >> x;               \
        v.pb(x);                \
    }

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

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 2 * (n - i) - 1; j >= 0; j--)
            cout << " ";
        for (int j = 0; j <= i; j++)
        {
            if (j != 0)
                cout << " ";
            cout << j;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (j >= 0)
                cout << " ";
            cout << j;
        }
        newline;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 2 * (n - i) - 1; j >= 0; j--)
            cout << " ";
        for (int j = 0; j <= i; j++)
        {
            if (j != 0)
                cout << " ";
            cout << j;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (j >= 0)
                cout << " ";
            cout << j;
        }
        newline;
    }

    return 0;
}
