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
        vector<pair<int, int>> first, second;
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            vi vec(m);
            for (int i = 0; i < m; i++)
                cin >> vec[i];
            sort(all(vec));
            first.pb({vec[0], i});
            second.pb({vec[1], i});
        }
        sort(all(first));
        sort(all(second));
        // for (auto i : first)
        //     cout << i.first << " " << i.second << endl;
        // newline;
        // for (auto i : second)
        //     cout << i.first << " " << i.second << endl;
        // newline;
        ll sum = first[0].first;
        for (int i = 1; i < sz(second); i++)
            sum += second[i].first;
        print(sum);
    }
    return 0;
}