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
    string s;
    cin >> s;
    int n = sz(s);

    unordered_map<char, int> count;
    int left = 0, mnLen = n + 1;

    for (int i = 0; i < n; i++)
    {
        count[s[i]]++;

        while (count['1'] > 0 && count['2'] > 0 && count['3'] > 0)
        {
            mnLen = min(mnLen, i - left + 1);
            count[s[left]]--;
            if (count[s[left]] == 0)
                count.erase(s[left]);
            left++;
        }
    }

    if (mnLen == n + 1)
        print(0);
    else
        print(mnLen);;
}

int main()
{
    fast_io;

    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}