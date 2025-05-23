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
        int n,k,q;
        cin >> n >> k >> q;
        vecIn(vec,n);
        vll days;
        for(int i=0;i<n;i++)
        {
          if(vec[i]<=q)
             days.pb(i);
        }
        int cnt = 0, consCnt = 0;
        vll consDays;
        
        for (int i = 0; i < days.size(); i++)
        {
            if (i == 0 || days[i] == days[i - 1] + 1)
            {
                consCnt++;  
            }
            else
            {
                if (consCnt >= k)
                {
                    consDays.push_back(consCnt);
                }
                consCnt = 1; 
            }
        }
        if (consCnt >= k)
        {
            consDays.push_back(consCnt);
        }

        // cout << "Consecutive days streaks >= " << k << " : ";
        // for (ll streak : consDays)
        // {
        //     cout << streak << " ";
        // }
        // newline;
        
        ll ans = 0;
        for (ll i : consDays)
        {
            if (i >= k)
            {
                ans += (i - k + 1) * (i - k + 2) / 2;
            }
        }

        print(ans);
    }
    return 0;
}