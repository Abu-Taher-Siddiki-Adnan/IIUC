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
#define vPi vector<pi>
#define vPll vector<pll>
#define uMap unordered_map<int, int>
#define rev(n) n.rbegin(), n.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES\n"
#define No cout << "NO\n"
#define print(n) cout << n << endl
#define newline cout << endl
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, n) FOR(i, 0, n)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int M = 100005;
vector<char> ok(M);

void solve()
{

    int n;
    cin >> n;
    ok[n] ? Yes : No;
}

int main()
{
    fast_io;
    vi v;

    bool ini = false;

    if (!ini)
    {
        for (int i = 10; i < M; ++i)
        {
            bool is_valid = true;
            int j = i;
            while (j)
            {
                if (j % 10 >= 2)
                {
                    is_valid = false;
                    break;
                }
                j /= 10;
            }
            if (is_valid)
                v.pb(i);
        }

        ok[1] = 1;
        for (int i = 1; i < M; ++i)
        {
            if (!ok[i])
                continue;
            for (auto &e : v)
            {
                if (i * e >= M)
                    break;
                ok[i * e] = 1;
            }
        }
        ini = true;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
