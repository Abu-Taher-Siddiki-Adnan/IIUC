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

const int N = 100000;
vi primes;

void sieve()
{
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;

    for (int i = 2; i <= N; i++)
        if (is_prime[i])
            primes.pb(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(); 

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        int p1 = *lower_bound(all(primes), 1 + d);
        int p2 = *lower_bound(all(primes), p1 + d);
        print(p1 * p2);
    }
    return 0;
}
