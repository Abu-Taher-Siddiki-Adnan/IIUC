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
        ll n;
        cin >> n;
        vecIn(vec, n);
        ll maxi = vec[0];
        int indx = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, vec[i]);
            if (maxi == vec[i])
                indx = i;
        }
        if (indx == n - 1)
        {
            print(0);
            continue;
        }
        ll cnt = vec[n-1];
        unordered_map<ll, int> freq;
        for (int i = n - 1; i >= 0; i--)
        {
            cnt = max(cnt, vec[i]);
            if (cnt != maxi)
                freq[cnt]++;
            else
                break;
        }
        print(sz(freq));
    }
    return 0;
}