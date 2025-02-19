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
    vll v(n);                   \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
#define vecOut(v, n)            \
    for (int i = 0; i < n; i++) \
        cout << v[i] << " ";    \
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
        vecIn(vec, n);

        map<ll, int> freq;
        for (int x : vec)
            freq[x]++;

        int oddCnt = 0, pairs = 0, zeroCnt = freq[0];
        for (auto v : freq)
        {
            if (v.first != 0)
            {
                if (v.second % 2)
                    oddCnt++;
                pairs += v.second / 2;
            }
        }

        int ans = oddCnt + (zeroCnt + pairs > 0 ? 1 : 0);
        print(ans);
    }
    return 0;
}
