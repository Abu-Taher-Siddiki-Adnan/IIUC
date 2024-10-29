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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    vi qur(k);
    for (int i = 0; i < k; i++)
        cin >> qur[i];
    int j = 0;
    while (k--)
    {
        int cur = qur[j];
        bool found = false;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (vec[m] == cur)
            {
                found = true;
                break;
            }
            else if (vec[m] > cur)
                r = m - 1;
            else if (vec[m] < cur)
                l = m + 1;
        }
        if (found)
            Y;
        else
            N;
        j++;
    }
    return 0;
}