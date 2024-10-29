#include <bits/stdc++.h>

using namespace std ;

bool is_prime (int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n ; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        if (is_prime(n))
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }

    return 0 ;
}