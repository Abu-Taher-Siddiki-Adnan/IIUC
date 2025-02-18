#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define sz(x) (int)x.size()
#define pb push_back
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl
#define print(n) cout << n << endl

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
        cin >> s;
        bool ok = false;
        
        for (int mask = 0; mask < 8; mask++) 
        {
            int bal = 0;
            bool good = true;
            
            for (char &c : s)
            {
                int p = c - 'A';
                if ((mask & (1 << p)))
                    bal++;
                else
                    bal--;
                
                if (bal < 0)
                {
                    good = false;
                    break;
                }
            }
            
            if (bal == 0 && good)
            {
                ok = true;
                break;
            }
        }
        
        ok ? Yes : No;
    }
    return 0;
}