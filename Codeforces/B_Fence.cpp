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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vecIn(vec, n);
    if (k == 1)
    {
        auto it = min_element(vec.begin(), vec.end());
        int index = it - vec.begin();
        cout << index + 1 << endl;
    }
    else if (n == k)
    {
        print(1);
    }
    else
    {
        ll sum = 0;
        for (int i = 0; i < k; i++)
            sum += vec[i];

        ll mn = sum;
        int indx = 0;

        for (int i = 1; i <= n - k; i++)
        {
            sum = sum - vec[i - 1] + vec[i + k - 1];
            if (sum < mn)
            {
                mn = sum;
                indx = i;
            }
        }

        print(indx + 1);
    }

    return 0;
}
