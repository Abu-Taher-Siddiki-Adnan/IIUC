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
        string s;
        cin >> s;
        string temp = s;
        int cnt0 = 0, cnt1 = 0;
        cnt0 = count(all(s), '0');
        cnt1 = count(all(s), '1');
        for (int i = 0; i < sz(s); i++)
        {
            if (temp[i] == '0')
            {
                if (cnt1 > 0)
                    cnt1--;
                else
                    break;
            }
            else if (temp[i] == '1')
            {
                if (cnt0 > 0)
                    cnt0--;
                else
                    break;
            }
        }
        int ans = cnt0 + cnt1;
        print(ans);
    }
    return 0;
}