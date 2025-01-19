//Insertion Sort
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++) {
        int cur = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > cur) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = cur;
    }

    for (int i : v) {
        cout << i << " ";
    }

    return 0;
}
