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
        string s;
        cin >> s;
        int q;
        cin >> q;
        int l = sz(s);
        int cnt = 0;
        for (int i = 0; i + 3 < l; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
                cnt++;
        }
        while (q--)
        {
            int p;
            char v;
            cin >> p >> v;
            p--; 
            for (int i = max(0, p - 3); i <= p && i + 3 < l; i++)
            {
                if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
                    cnt--;
            }
            s[p] = v;
            for (int i = max(0, p - 3); i <= p && i + 3 < l; i++)
            {
                if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
                    cnt++;
            }
            if (cnt > 0)
                Y;
            else
                N;
        }
    }

    return 0;
}
