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
        int n, k;
        cin >> n >> k;

        unordered_map<int, vi> brand_costs;
        for (int i = 0; i < k; i++)
        {
            int brand, cost;
            cin >> brand >> cost;
            brand_costs[brand].pb(cost);
        }

        vll total_brand_values;
        for (auto &[brand, costs] : brand_costs)
        {
            sort(costs.rbegin(), costs.rend()); 
            ll total = 0;
            for (int cost : costs)
            {
                total += cost;
            }
            total_brand_values.pb(total);
        }
        sort(total_brand_values.rbegin(), total_brand_values.rend()); 
        ll max_earnings = 0;
        for (int i = 0; i < min(n, sz(total_brand_values)); ++i)
        {
            max_earnings += total_brand_values[i];
        }

        print(max_earnings);
    }

    return 0;
}
