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
    for (int i = 0; i < n; i++) \
    {                           \
        ll x;                   \
        cin >> x;               \
        v.pb(x);                \
    }

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
        string s;
        int p;
        cin >> s >> p;

        int cost = 0;
        string alp = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < sz(s); i++)
        {
            auto it = find(all(alp), s[i]);
            int c = it - alp.begin();
            cost += (c + 1);
        }

        if (cost <= p)
            print(s);
        else
        {
            string temp = s;
            sort(all(temp));

            string ans = "";
            int x = 0;
            map<char, int> freq;
            for (int i = 0; i < sz(temp); i++)
            {
                auto it = find(all(alp), temp[i]);
                int c = it - alp.begin();
                x += (c + 1);
                if (x <= p)
                {
                    ans += temp[i];
                    freq[temp[i]]++;
                }
            }
            unordered_set<char> keep(all(ans));
            for (char c : s)
            {
                if (keep.count(c) and freq[c] > 0)
                {
                    cout << c;
                    freq[c]--;
                }
            }
            newline;
        }
    }

    return 0;
}
