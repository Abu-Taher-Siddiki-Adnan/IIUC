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
        int n, k;
        cin >> n >> k;
        vecIn(vec, n);
        sort(all(vec));

        ll mul = 1;
        for (int i = 0; i < n; i++)
        {
            mul *= vec[i];
        }

        if (mul % k == 0)
        {
            print(0);
            continue;
        }

        if (k != 4)
        {
            vll newVec(n);
            for (int i = 0; i < n; i++)
            {
                if (vec[i] < k)
                    newVec[i] = k - vec[i];
                else
                {
                    ll d = vec[i] / k;
                    d++;
                    ll x = d * k - vec[i];
                    newVec[i] = x;
                }
            }
            sort(all(newVec));
            print(newVec[0]);
            continue;
        }

        int cnt = 0;
        for (ll num : vec)
        {
            if (num % 2 == 0)
                cnt++;
        }
        ll ans =  max(0, 2 - cnt);
        ll mod = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            mod = max((vec[i] % k), mod);
        }
        if (n >= 2 and k == 4)
            cout << min(k - mod, ans) << endl;
        else
            cout << k - mod << endl;
    }
    return 0;
}
