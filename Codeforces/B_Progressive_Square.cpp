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
        int n, c, d;
        cin >> n >> c >> d;
        vll b(n * n);
        for (int i = 0; i < n * n; i++)
            cin >> b[i];

        sort(all(b));
        map<ll, int> freq;
        for (int i = 0; i < n * n; i++)
            freq[b[i]]++;

        vector<vector<ll>> vec(n, vector<ll>(n));
        vec[0][0] = b[0];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (j == 0)
                    vec[i][j] = vec[i - 1][j] + c;
                else
                    vec[i][j] = vec[i][j - 1] + d;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << vec[i][j] << " ";
        //     }
        //     newline;
        // }
        // newline;

        // vecOut(b,n*n);

        bool hasValue = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (freq[vec[i][j]] == 0)
                {
                    hasValue = false;
                    break;
                }
                else
                    freq[vec[i][j]]--;
            }
            if (!hasValue)
                break;
        }

        if (hasValue)
            Yes;
        else
            No;
    }
    return 0;
}