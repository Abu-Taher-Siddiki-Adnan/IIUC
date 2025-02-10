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
        string S, T;
        cin >> S >> T;
        sort(all(S));
        bool ok = true;
        for (int i = 0; i < sz(S) - 1; i++)
        {
            if (S[i] == T[0] and S[i + 1] == T[1])
            {
                for (int j = i + 1; j < sz(S) - 1; j++)
                {
                    if (S[j] == T[1] and S[j+1]==T[2])
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            print(S);
        else
        {
            string ss = "";
            for (int i = 0; i < sz(S); i++)
            {
                if (S[i] == T[0])
                    ss += S[i];
            }
            for (int i = 0; i < sz(S); i++)
            {
                if (S[i] == T[2])
                    ss += S[i];
            }
            for (int i = 0; i < sz(S); i++)
            {
                if (S[i] == T[1])
                    ss += S[i];
            }
            sort(all(S));
            for (int i = 0; i < sz(S); i++)
            {
                if (S[i] != T[0] and S[i] != T[1] and S[i] != T[2])
                    ss += S[i];
            }
            print(ss);
        }
    }
    return 0;
}