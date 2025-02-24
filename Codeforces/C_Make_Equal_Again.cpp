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
        cin >> n;
        vecIn(vec,n);
        vi lFirst, lLast;
        ll f = vec[0];
        ll l = vec[n-1];

        for(int i=0; i<n; i++)
        {
            if(vec[i] != f)
                lFirst.pb(i);
            if(vec[i] != l)
                lLast.pb(i);
        }

        int s1 = sz(lFirst);
        int s2 = sz(lLast);
        
        if (s1 == 0 || s2 == 0)  
        {
            print(0);
            continue;
        }

        int ans1 = lFirst[s1 - 1] - lFirst[0] + 1;
        int ans2 = lLast[s2 - 1] - lLast[0] + 1;
        
        print(min(ans1, ans2));
    }
    return 0;
}