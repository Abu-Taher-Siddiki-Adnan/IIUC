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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi vec1, vec2;
        set<char> st1, st2;
        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            st1.insert(s[i]);
            vec1.pb(sz(st1));
            st2.insert(s[j]);
            vec2.pb(sz(st2));
        }

        reverse(all(vec2));
        // vecOut(vec1,n);
        // vecOut(vec2,n);
        // newline;
        int maxi = 0;
        for (int i = 0; i < n-1; i++)
            maxi = max(vec1[i] + vec2[i+1], maxi);
        print(maxi);
    }
    return 0;
}