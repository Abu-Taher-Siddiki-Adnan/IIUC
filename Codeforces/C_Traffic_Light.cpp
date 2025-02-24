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
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        if (c == 'g')
        {
            print(0);
            continue;
        }
        s += s;
        vi cur, grn;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                cur.push_back(i);
            else if (s[i] == 'g')
                grn.push_back(i);
        }

        int max_wait = 0;
        for (int i = 0, j = 0; i < cur.size(); i++)
        {
            while (j < grn.size() && grn[j] < cur[i])
            {
                j++;
            }
            if (j < grn.size())
                max_wait = max(max_wait, grn[j] - cur[i]);
        }

        print(max_wait);
    }
    return 0;
}