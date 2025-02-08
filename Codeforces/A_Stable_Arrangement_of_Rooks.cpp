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
        int n, k;
        cin >> n >> k;
        int rocks = (n + 1) / 2;
        if (k > rocks)
            print(-1);
        else
        {
            int r = 1;
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                bool PR = false;
                for (int j = 1; j <= n; j++)
                {
                    if (j == r and i % 2 != 0 and cnt!=k)
                    {
                        cout << 'R';
                        PR = true;
                        cnt++;
                    }
                    else
                        cout << '.';
                }
                if (PR)
                    r += 2;
                cout << endl;
            }
        }
    }
    return 0;
}