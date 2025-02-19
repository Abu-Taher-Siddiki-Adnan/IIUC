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

bool allZ(const string &s)
{
    return all_of(s.begin(), s.end(), [](char c)
                  { return c == 'z'; });
}

bool incHalf(string &L)
{
    int len = sz(L);
    for (int i = len - 1; i >= 0; i--)
    {
        if (L[i] < 'z')
        {
            L[i]++;
            fill(L.begin() + i + 1, L.end(), 'a');
            return true;
        }
    }
    return false;
}

string makePal(string L, int n)
{
    int h = (n + 1) / 2;
    string pal(n, ' ');
    for (int i = 0; i < h; i++)
        pal[i] = L[i];
    int m = (n % 2 == 0) ? h - 1 : h - 2;
    for (int i = m; i >= 0; i--)
        pal[n - 1 - i] = L[i];
    return pal;
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
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (allZ(s))
        {
            print(-1);
            continue;
        }

        int h = (n + 1) / 2;
        string L = s.substr(0, h);
        string pal = makePal(L, n);

        if (pal <= s)
        {
            if (!incHalf(L))
            {
                print(-1);
                continue;
            }
            pal = makePal(L, n);
        }

        print(pal);
    }
    return 0;
}
