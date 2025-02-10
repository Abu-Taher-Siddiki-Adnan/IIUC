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
        for (int i = 0; i < n; i++)
            vec[i] = abs(vec[i]);
        map<ll, ll> freq;
        for (auto i : vec)
            freq[i]++;
        int ans = 0;
        // for (auto i : freq)
        //     cout << i.first << " " << i.second << endl;
        // cout << endl;
        for (auto i : freq)
        {
            if (i.first == 0)
                ans += 1;
            else
                ans += min(2LL, i.second);
        }
        print(ans);
    }
    return 0;
}