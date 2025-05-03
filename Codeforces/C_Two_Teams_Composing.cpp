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
#define vecOut(v)                   \
    for (int i = 0; i < sz(v); i++) \
    {                               \
        cout << v[i] << " ";        \
    }                               \
    cout << endl;

void Solve()
{
    int n;
    cin >> n;
    vecIn(vec, n);
    if (n == 1)
    {
        print(0);
    }
    else
    {
        unordered_map<ll, int> freq;
        for (auto x : vec)
            freq[x]++;
        int max_frq = 0;
        for (auto x : freq)
        {
            if (x.second > max_frq)
                max_frq = x.second;
        }
        if (max_frq == 1)
            print(1);
        else if (max_frq > sz(freq))
            print(sz(freq));
        else if (max_frq == sz(freq))
            print(max_frq - 1);
        else
            print(max_frq);
    }
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
        Solve();
    }

    return 0;
}