#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vPi vector<pair<int, int>>
#define vPll vector<pair<ll, ll>>
#define uMap unordered_map<int, int>
#define rev(n) n.rbegin(), n.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl
#define print(n) cout << n << endl
#define Pi M_PI
#define newline cout << endl
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, n) FOR(i, 0, n)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define vecIn(v, n, type)       \
    vector<type> v(n);          \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

#define vecOut(v)         \
    for (auto &x : v)     \
        cout << x << " "; \
    cout << endl;

void solve()
{
    int n;
    cin >> n;
    vecIn(vec, n, int);
    sort(all(vec));
    bool possible = true;
    int p = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[i] - vec[i - 1] == 1 or (vec[i] % 2 == vec[i - 1] % 2))
        {
            p++;
            i++;
        }
    }
    if (p * 2 == n)
        Yes;
    else
    {
        vi odd, even;
        for (int i : vec)
        {
            if (i % 2 == 0)
                even.pb(i);
            else
                odd.pb(i);
        }
        sort(all(odd));
        sort(all(even));
        if (sz(odd) % 2 == 0)
            Yes;
        else
        {
            bool possible = false;
            for (int i = 0; i < sz(even); i++)
            {
                for (int j = 0; j < sz(odd); j++)
                {
                    if (abs(odd[j] - even[i]) == 1)
                    {
                        possible = true;
                        break;
                    }
                }
                if (possible)
                    break;
            }
            if (possible)
                Yes;
            else
                No;
        }
    }
}
int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}