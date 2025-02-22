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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> vec(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> vec[i][j];
        }
        if (n == 1)
        {
            print(n);
            continue;
        }
        for (int i = 0; i < n; i++)
            sort(all(vec[i]));
        bool possible;
        for (int i = 0; i < n; i++)
        {
            possible = true;
            for (int j = 0; j < m - 1; j++)
            {
                if (vec[i][j + 1] - vec[i][j] != n)
                {
                    possible = false;
                    break;
                }
                if (!possible)
                    break;
            }
        }
        if (!possible)
        {
            print(-1);
            continue;
        }
        vector<pair<int, int>> result;
        for (int i = 0; i < n; i++)
        {
            int x = vec[i][0];
            int y = i + 1;
            result.push_back({x, y});
        }
        sort(all(result));
        for (auto i : result)
            cout << i.second << " ";
        newline;
    }
    return 0;
}